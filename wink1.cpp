#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv){
	
	cv::namedWindow("Wink", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	//open camera
	cap.open(0);//first camera available
	
	if(!cap.isOpened()){
		std::cout << "Could not open camera." << std::endl;
		return -1;
	}
	
	std::cout << "Opened camera." << std::endl;
	//display video live 
	cv::Mat frame;
	for(;;){
		cap >> frame;
		//std::cout << "Opened frame." << std::endl;
		if(frame.empty()){
			std::cout << "End of frames." << std::endl;
			//break;
		}
		cv::imshow("Wink", frame);
		if(cvWaitKey(30) >=0)
			break;
	}
	return 0;
}
