#ifndef VIDEO_STREAMER
#define VIDEO_STREAMER

/*
 * VideoStreamer
 * 
 * 
 * */

#include <opencv2/opencv.hpp>
#include <boost/circular_buffer.hpp>
#include <iostream>


class VideoStreamer {
	public: 
		VideoStreamer(): buf{30} {};
		void startStream(int cameraID, cv::String windowName);
		void playbackBuffer(cv::String windowName);
		
	private:
		cv::VideoCapture camera;
		//has a circular buffer, assuming 30 fps
		boost::circular_buffer<cv::Mat> buf;
};

#endif
