# version less than cmake 3.2 will give
# errors while build, as the new the older version
# less than this wont be able to support the new
# cmake features implemented
cmake_minimum_required(VERSION 3.2)

# tests for only C and C++ compiler
project(TimeIt VERSION 0.0.0 LANGUAGES C, CXX)

# primary tools for the project
# optional keyword like WIN32, MACOSX_BUNDLE
# not needed here as javascript front end is used for
# cross-platform compatibility
add_executable(timeIt 
	main.cpp
	debug.cpp
)

# diagnostic tools for development and testing
add_executable(testTool testTool.cpp)


