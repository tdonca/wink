
/*
 * VideoStreamer
 * 
 * */

#include <opencv2/opencv.hpp>
#include <iostream>
#include "VideoStreamer.h"



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
	int delayCounter = 20;
	bool countdown = false;
	bool flash = false;
	while(1){
		camera >> frame;
		buf.push_back(frame.clone());
		if(frame.empty()){
			std::cerr << "No frame found." << std::endl;
			break;
		}
		
		if(flash){
			cv::rectangle(frame, cv::Point(0,0), cv::Point(width, height), 
							cv::Scalar(255,255,255), -1);
			flash = false;
		}
		
		if(countdown){
			--delayCounter;
			if(delayCounter == 0){
				countdown = false;
				delayCounter = 20;
				std::cout << "Wink playback initiated." << std::endl;
				playbackBuffer(windowName);
			}
		}
		
		//display current frame to window
		cv::imshow(windowName, frame);
		
		char key = cvWaitKey(30);
		//check for key pressed = 'r' to initiate playback
		if(key == 114){
			//playback last second of video
			std::cout << "Wink countdown initiated." << std::endl;
			countdown = true;
			flash = true;
		}
		else if(key > 0){
			break;
		}
		
		
		
	}
	
}

void VideoStreamer::playbackBuffer(cv::String windowName){
	
	for(int i = 0; i < buf.size(); i++){
		if(buf[i].empty()){
				std::cerr << "No playback frame found." << std::endl;
				break;
		}
		cv::imshow(windowName, buf[i]);
		if(cvWaitKey(33) > 0){
			break;
		}
	}
	
}
