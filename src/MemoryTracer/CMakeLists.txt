cmake_minimum_required(VERSION 3.2)

project(MemoryTracer)
add_library(MemoryTracer STATIC)

# Adding the directories
target_include_directories(MemoryTracer PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include)

# Managing the header files for the target sources
target_sources(MemoryTracer PUBLIC
	include/MemoryTracer/MemoryTracerListener.h
	include/MemoryTracer/MemoryTracerProducer.h)

target_sources(MemoryTracer PRIVATE
	MemoryTracerProducer.cpp)

