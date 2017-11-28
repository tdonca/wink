#ifndef VIDEO_STREAMER
#define VIDEO_STREAMER

/*
 * VideoStreamer
 * 
 * 
 * */

#include <opencv2/opencv.hpp>
#include <iostream>


class VideoStreamer {
	public: 
		VideoStreamer();
		void startStream(int cameraID, cv::String windowName);
		
	private:
		cv::VideoCapture camera;
		//has a detector
};

#endif
