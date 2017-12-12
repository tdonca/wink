#ifndef VIDEO_STREAMER
#define VIDEO_STREAMER

/*
 * VideoStreamer
 * 
 * 
 * */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <boost/circular_buffer.hpp>
#include <string>
#include <vector>
#include <future>



class VideoStreamer {
	public: 
		VideoStreamer(int _width, int _height) 
			:width{_width},
			 height{_height},
			 camera{}, 
			 replay_buf{30}, 
			 face_classifier{}, 
			 eye_classifier{},
			 firstDetection{true},
			 frameCounter{0},
			 winkCounter{0},
			 detectorFuture{} {
			
			if(!face_classifier.load(face_cascade)){
				std::cerr << "Error loading face cascade.\n";
			}	 
			if(!eye_classifier.load(eye_cascade)){
				std::cerr << "Error loading eye cascade.\n";
			}
					
		};
		void startStream(int cameraID, cv::String windowName);
		std::vector<cv::Rect> detectEyes(cv::Mat frame);
		void playbackBuffer(cv::String windowName);
		
	private:
		int width, height;
		cv::VideoCapture camera;
		boost::circular_buffer<cv::Mat> replay_buf;
		static const std::string face_cascade;
		static const std::string eye_cascade;
		cv::CascadeClassifier face_classifier;
		cv::CascadeClassifier eye_classifier;
		bool firstDetection;
		int frameCounter;
		int winkCounter;
		std::future<std::vector<cv::Rect> > detectorFuture;
};

#endif
