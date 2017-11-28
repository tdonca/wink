
/*
 * VideoStreamer
 * 
 * */

#include <opencv2/opencv.hpp>
#include <iostream>
#include "VideoStreamer.h"



/* Constructor */
VideoStreamer::VideoStreamer(){

}


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
		
		//display current frame to window
		cv::imshow(windowName, frame);
		//check for key pressed to end stream
		if(cvWaitKey(5) > 0){
			break;
		}
	}
	
}
