#include <opencv2/opencv.hpp>
#include <iostream>

int detectFaceAndEyes(cv::Mat frame);

cv::String face_cascade = "data/haarcascade_frontalface_alt2.xml";
cv::String eye_cascade = "data/haarcascade_eye_tree_eyeglasses.xml";
cv::CascadeClassifier face_classifier;
cv::CascadeClassifier eye_classifier;

int main(int argc, char** argv){
	
	cv::namedWindow("Wink", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	//open camera
	cap.open(0);//first camera available
	
	if(!cap.isOpened()){
		std::cerr << "Could not open camera." << std::endl;
		return -1;
	}
	
	//load classifiers
	if(!face_classifier.load(face_cascade)){
		std::cerr << "Could not load face cascade." << std::endl;
		return -1;
	}
	if(!eye_classifier.load(eye_cascade)){
		std::cerr << "Could not load eye cascade." << std::endl;
		return -1;
	}
	
	
	
	//display video live 
	cv::Mat frame;
	for(;;){
		cap >> frame;
		if(frame.empty()){
			std::cerr << "No frame found." << std::endl;
			break;
		}
		
		//run classifiers on frame
		if (detectFaceAndEyes(frame) == -1){
			std::cout << "No face found" << std::endl;
		}
		cv::imshow("Wink", frame);
		if(cvWaitKey(10) >=0)
			break;
	}
	return 0;
}

int detectFaceAndEyes(cv::Mat frame){
	std::vector<cv::Rect> faces;
	cv::Mat gray;
	//grayscale
	cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
	//normalization
	cv::equalizeHist(gray, gray);
	
	//detect faces
	face_classifier.detectMultiScale(gray, faces, 1.1, 3, 0|cv::CASCADE_SCALE_IMAGE,
							cv::Size(75,75));
	
	if(faces.size() == 0){
		return 0;
	}
	//detect each face
	for(size_t i = 0; i < faces.size(); i++){
		cv::Point topleft(faces[i].x, faces[i].y);
		cv::Point bottomright(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
		cv::rectangle(frame, topleft, bottomright, cv::Scalar(200, 100, 0) );
		
		//detect each eye on the face
		cv::Mat faceROI = gray(faces[i]);
		std::vector<cv::Rect> eyes;
		eye_classifier.detectMultiScale(faceROI, eyes, 1.1, 3, 0|cv::CASCADE_SCALE_IMAGE,
							cv::Size(20 , 20), cv::Size(50, 50));
		for(size_t j = 0; j < eyes.size(); j++){
			cv::Point eye(faces[i].x + eyes[j].x + eyes[j].width/2,
						faces[i].y + eyes[j].y + eyes[j].height/2);
			int radius = cvRound((eyes[j].width + eyes[j].height)/4);
			cv::circle(frame, eye, radius, cv::Scalar(200, 200, 0));
		}	
	}
	
	return 1;
}
