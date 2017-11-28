#include <opencv2/opencv.hpp>
#include <iostream>

#include "VideoStreamer.h"
//when to include header files?

int main(int argc, char* argv[]){
	//create window
	cv::namedWindow("Wink", cv::WINDOW_AUTOSIZE);
	cv::resizeWindow("Wink", 500, 400);
	cv::moveWindow("Wink", 300, 300);
	
	//create video stream
	VideoStreamer stream{};
	
	//start streaming
	stream.startStream(0, "Wink");
	std::cout << "Finished streaming." << std::endl;
	return 0;
}
