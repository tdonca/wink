
/*
 * VideoStreamer
 * 
 * */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <future>
#include <vector>
#include <chrono>
#include "VideoStreamer.h"


//pretrained face and eye classifiers
const std::string VideoStreamer::face_cascade{"data/haarcascade_frontalface_alt2.xml"};
const std::string VideoStreamer::eye_cascade{"data/haarcascade_eye_tree_eyeglasses.xml"};


/* startStream */
void VideoStreamer::startStream(int cameraID, cv::String windowName ){
	
	//open camera specified by cameraID, 0 is the default camera detected
	camera.open(cameraID);
	if(!camera.isOpened()){
		std::cerr << "Camera could not be opened!" << std::endl;
		return;
	}
	std::cout << "Camera " << cameraID << " opened." << std::endl;
	
	//stream frames continuously until a key is pressed
	cv::Mat frame;
	while(1){
		camera >> frame;
		if(frame.empty()){
			std::cerr << "No frame found." << std::endl;
			break;
		}
		
		
		//Store frame for playback
		replay_buf.push_back(frame.clone());
		
		
		//**********************//
		//dispach concurrent processing of the frame with the classifiers
		//get back a vector of rectangles to draw on the screen
		//**********************//
		
		if(firstDetection){
			//TODO: find a way to get past the many clones of the frame
			detectorFuture = std::async(std::launch::async, &VideoStreamer::detectEyes, this, frame.clone() );
			if(!detectorFuture.valid()){
				std::cerr << "Future is invalid!" << std::endl;
				return;
			}
			firstDetection = false;
		}
		
		//std::cout << "Frame " << frameCounter << std::endl;
		//check if detection task is done
		if( frameCounter > 1 && detectorFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready ){
			//std::cout << "Future ready\n";
			std::vector<cv::Rect> eyes = detectorFuture.get();
			//std::cout << "Was able to get\n";
			
			//dispach new detection task
			detectorFuture = std::async(std::launch::async, 
									&VideoStreamer::detectEyes, this, frame.clone() );
			
			
			//Detect winking
			if(eyes.size() >= 2){ //eyes opened
				winkCounter = 0;
			}
			else{//possible wink
				++winkCounter;
			}
			if(winkCounter > 1){
				std::cout << "Wink!" << std::endl;
			}
			
			
			//draw the eye features
			for(size_t i = 0; i < eyes.size(); ++i){
				cv::rectangle(frame, eyes[i], cv::Scalar(255,0,0), 4);
			}
			
			frameCounter = 0;
		}
		
		
		//display current frame to window
		cv::imshow(windowName, frame);
		
		
		//check for key pressed to end stream
		if(cvWaitKey(10) > 0){
			break;
		}
		
		
		//update Frame counter
		++frameCounter;
	}
	
}


//return a vector of Rectangle coordinates where eyes are detected
std::vector<cv::Rect> VideoStreamer::detectEyes(cv::Mat frame){
	//the rectangle should have proper coordinates in the main frame space
	//correct from detection within face rectangle only
	std::vector<cv::Rect> features;
	cv::Mat procFrame;
	//grayscale
	cv::cvtColor(frame, procFrame, cv::COLOR_BGR2GRAY);
	//blur
	cv::medianBlur(procFrame, procFrame, 3);
	//normalize
	cv::equalizeHist(procFrame, procFrame);
	
	
	//detect any faces in the frame
	std::vector<cv::Rect> faces;
	face_classifier.detectMultiScale(procFrame, faces, 1.1, 3, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(50, 50));
	for(size_t i = 0; i < faces.size(); ++i){
		
		//detect eyes
		cv::Mat face = procFrame(faces[i]);
		std::vector<cv::Rect> eyes;
		eye_classifier.detectMultiScale(face, eyes, 1.1, 5, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
		
		
		//correct eye feature coordinates for drawing
		for(size_t j = 0; j < eyes.size(); ++j){
			eyes[j].x += faces[i].x;
			eyes[j].y += faces[i].y;
			features.push_back(eyes[j]);
		}
	}
	
	
	
	return features;
}
