#include <opencv2/opencv.hpp>
#include <iostream>

#include "VideoStreamer.h"
//when to include header files?

int main(int argc, char* argv[]){
	//create window
	cv::namedWindow("Wink", cv::WINDOW_NORMAL);
	int width = 1600, height = 900;
	cv::resizeWindow("Wink", 1600, 900);
	cv::moveWindow("Wink", 300, 300);
	
	//create video stream
	VideoStreamer stream{width, height};
	
	//start streaming
	stream.startStream(0, "Wink");
	std::cout << "Finished streaming." << std::endl;
	return 0;
}
