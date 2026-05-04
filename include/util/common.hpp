#pragma once
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <stdint.h>
#define libgranturismo_unimpl(name) std::cerr << name << ": unimplemented @ " << __FILE__ << ":" << __LINE__ << std::endl; abort();


namespace libgranturismo {
	namespace util {
		static inline uint64_t read_bits(uint64_t value, int base, int length) {
			uint64_t mask = 0;
			for (int i = 0; i < length; i++) {
				mask = mask | (1 << (base + i));
			}
			return (value & mask) >> base;
		}

		unsigned int align(int original, int alignment);
	}
}