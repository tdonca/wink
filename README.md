# Wink

This application uses OpenCV to implement eye recognition to automatically detect winking.

### To run this project:
	1. Remove CMakeCache.txt
	2. Open CMakeLists.txt and properly add the dependency libraries and headers listed below. (I used environment variables to point to the root directories of the libraries)
	3. Run the following commands:
		$> cmake .
		$> make
	4. execute using:
		$> ./wink1

### Dependencies:
	1. OpenCV 3.x
	2. Boost Library
	3. CMake
