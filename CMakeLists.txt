set (CMAKE_CXX_STANDARD 11)

cmake_minimum_required(VERSION 2.8)
project( wink1 )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} $ENV{BOOST_ROOT} )
add_executable( wink1 wink1.cpp VideoStreamer.cpp )
target_link_libraries( wink1 ${OpenCV_LIBS}  )
