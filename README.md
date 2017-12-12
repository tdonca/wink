# Wink

This application uses OpenCV to implement eye recognition to automatically detect winking.

### To run this project:
	1. Remove CMakeCache.txt
	2. Open CMakeLists.txt and properly add the dependency libraries and 
	   headers listed below. (I used environment variables to point to 
	   the root directories of the libraries)
	3. Run the following commands:
		$> cmake .
		$> make
	4. execute using:
		$> ./wink1

### Dependencies:
	1. OpenCV 3.x
	2. Boost Library
	3. CMake

### Hiatus:
	The default Haar Cascade Classifier model provided by OpenCV for eye 
	detection is not very reliable. Specifically, there is a strong bias in 
	detecting the left eye, but not the right eye, at least in the lighting
	conditions I have tested. Also, the classifier sometimes labels a closed 
	eye as still a regular eye, defeating the purpose of detecting a wink.
	
	To overcome this, I need to train my own classifier, focusing only on eye
	features, and distinguishing between open and closed eyes. Since this is 
	my first substantial attempt at computer vision and machine learning development,
	struggling with creating a custom dataset on top of figuring out how to properly
	create a classification model is not going to be productive.
	
	I will return to this project after I have more experience developing 
	image classification models, so I can focus my attention on the dataset 
	configuration and proper testing. 
