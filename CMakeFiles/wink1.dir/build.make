# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tudor/devCV/wink

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tudor/devCV/wink

# Include any dependencies generated for this target.
include CMakeFiles/wink1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wink1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wink1.dir/flags.make

CMakeFiles/wink1.dir/wink1.cpp.o: CMakeFiles/wink1.dir/flags.make
CMakeFiles/wink1.dir/wink1.cpp.o: wink1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tudor/devCV/wink/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wink1.dir/wink1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wink1.dir/wink1.cpp.o -c /home/tudor/devCV/wink/wink1.cpp

CMakeFiles/wink1.dir/wink1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wink1.dir/wink1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tudor/devCV/wink/wink1.cpp > CMakeFiles/wink1.dir/wink1.cpp.i

CMakeFiles/wink1.dir/wink1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wink1.dir/wink1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tudor/devCV/wink/wink1.cpp -o CMakeFiles/wink1.dir/wink1.cpp.s

CMakeFiles/wink1.dir/wink1.cpp.o.requires:

.PHONY : CMakeFiles/wink1.dir/wink1.cpp.o.requires

CMakeFiles/wink1.dir/wink1.cpp.o.provides: CMakeFiles/wink1.dir/wink1.cpp.o.requires
	$(MAKE) -f CMakeFiles/wink1.dir/build.make CMakeFiles/wink1.dir/wink1.cpp.o.provides.build
.PHONY : CMakeFiles/wink1.dir/wink1.cpp.o.provides

CMakeFiles/wink1.dir/wink1.cpp.o.provides.build: CMakeFiles/wink1.dir/wink1.cpp.o


# Object files for target wink1
wink1_OBJECTS = \
"CMakeFiles/wink1.dir/wink1.cpp.o"

# External object files for target wink1
wink1_EXTERNAL_OBJECTS =

wink1: CMakeFiles/wink1.dir/wink1.cpp.o
wink1: CMakeFiles/wink1.dir/build.make
wink1: /usr/local/lib/libopencv_shape.so.3.2.0
wink1: /usr/local/lib/libopencv_stitching.so.3.2.0
wink1: /usr/local/lib/libopencv_superres.so.3.2.0
wink1: /usr/local/lib/libopencv_videostab.so.3.2.0
wink1: /usr/local/lib/libopencv_viz.so.3.2.0
wink1: /usr/local/lib/libopencv_objdetect.so.3.2.0
wink1: /usr/local/lib/libopencv_calib3d.so.3.2.0
wink1: /usr/local/lib/libopencv_features2d.so.3.2.0
wink1: /usr/local/lib/libopencv_flann.so.3.2.0
wink1: /usr/local/lib/libopencv_highgui.so.3.2.0
wink1: /usr/local/lib/libopencv_ml.so.3.2.0
wink1: /usr/local/lib/libopencv_photo.so.3.2.0
wink1: /usr/local/lib/libopencv_video.so.3.2.0
wink1: /usr/local/lib/libopencv_videoio.so.3.2.0
wink1: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
wink1: /usr/local/lib/libopencv_imgproc.so.3.2.0
wink1: /usr/local/lib/libopencv_core.so.3.2.0
wink1: CMakeFiles/wink1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tudor/devCV/wink/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wink1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wink1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wink1.dir/build: wink1

.PHONY : CMakeFiles/wink1.dir/build

CMakeFiles/wink1.dir/requires: CMakeFiles/wink1.dir/wink1.cpp.o.requires

.PHONY : CMakeFiles/wink1.dir/requires

CMakeFiles/wink1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wink1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wink1.dir/clean

CMakeFiles/wink1.dir/depend:
	cd /home/tudor/devCV/wink && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tudor/devCV/wink /home/tudor/devCV/wink /home/tudor/devCV/wink /home/tudor/devCV/wink /home/tudor/devCV/wink/CMakeFiles/wink1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wink1.dir/depend

