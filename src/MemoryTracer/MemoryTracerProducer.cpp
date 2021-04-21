#include "MemoryTracer/MemoryTracerProducer.h"

// can include <thread> instead of <pthread> library to make in cross-compatible
#include <thread> 
#include <time>
#include <mutex>
#include <memory>

namespace memory_tracer {
	
	// start the memory sampling process
	void MemoryTracerProducer::start(){
		thread_ = std::make_unique<std::thread>(&MemoryTracer::run, this)
	}
	
	// joins to the main thread if the thread_ has stopped
	// executing the code 
	void MemoryTracerProducer::stop(){
		// check if the thread has complete its task 
		if(thread_ != nullptr && thread_->joinable()){
			thread_->join();
		}
		thread_.reset();
	}


	void MemoryTracerProducer::run() {
		generate_memory_usage();
	}

	void MemoryTracerProducer::generate_memory_usage(){
		std::cout << "Memory usage for the given program" << std::endl;
	}
}

