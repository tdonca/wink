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
		VideoStreamer(int _width, int _height): width{_width}, height{_height}, buf{30} {};
		void startStream(int cameraID, cv::String windowName);
		void playbackBuffer(cv::String windowName);
		
	private:
		int width;
		int height;
		cv::VideoCapture camera;
		//has a circular buffer, assuming 30 fps
		boost::circular_buffer<cv::Mat> buf;
};

#endif
