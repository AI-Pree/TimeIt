#ifndef MEMORY_TRACER_PRODUCER_H_
#define MEMORY_TRACER_PRODUCER_H_
#include <thread>
#include <mutex>
#include <iostream>
#include <cstdint>
#include <memory>

namespace memory_tracer {
	///
	// MemoryTracerProducer
	// This class generates the memory usage of the program throughout its
	// runtime
	///
	class MemoryTracerProducer {
		private:
			std::uint64_t sampling_period_in_ns;
			std::unique_ptr<std::thread> thread_;
			std::mutex handler_;

			void run();
			void generate_memory_usage(); // generate the memory usage for the listener
		public:
			explicit MemoryTracerProducer(std::uint64_t memory_sampling_period_in_ns):
				sampling_period_in_ns(memory_sampling_period_in_ns){}	

			void start();	// start the memory sampling
			void stop();	// end the memory sampling, usually after the lifetime of MemoryTracerProducer is over
			~MemoryTracerProducer(){ stop(); }
			
			// for now most of the constructor are disabled
			// this will also delete both the copy and move assign operators
			MemoryTracerProducer(const MemoryTracerProducer&) = delete;
			MemoryTracerProducer(MemoryTracerProducer&&) = delete;
	};
}

#endif

