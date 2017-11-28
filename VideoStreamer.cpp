
/*
 * VideoStreamer
 * 
 * */

#include <opencv2/opencv.hpp>
#include <iostream>
#include "VideoStreamer.h"



//~ /* Constructor */
//~ VideoStreamer::VideoStreamer(): buf{30} {
	
//~ }


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
		buf.push_back(frame.clone());
		if(frame.empty()){
			std::cerr << "No frame found." << std::endl;
			break;
		}
		
		//display current frame to window
		cv::imshow(windowName, frame);
		
		char key = cvWaitKey(30);
		//check for key pressed = 'r' to initiate playback
		if(key == 114){
			//playback last second of video
			std::cout << "Wink playback initiated." << std::endl;
			playbackBuffer(windowName);
		}
		else if(key > 0){
			break;
		}
	}
	
}

void VideoStreamer::playbackBuffer(cv::String windowName){
	//~ cv::namedWindow("Playback", cv::WINDOW_AUTOSIZE);
	//~ cv::imshow(windowName,  buf[1]);
	//~ cv::imshow("Playback", buf[25]);
	//~ cvWaitKey(1000);
	
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
