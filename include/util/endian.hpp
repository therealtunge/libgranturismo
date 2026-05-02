#pragma once
#include <stdint.h>

namespace libgranturismo {
	/// @brief basic utility functions
	namespace util {
		/// @brief enum defining endianness
		typedef enum {
			ENDIAN_BIG,
			ENDIAN_LITTLE
		} endianness;
		/// @brief endianness of current file
		/// @details used by the int reading functions to normalize the output
		extern endianness endian;
		/// @brief convert a 16 bit integer into little endian based on `util::endian`
		uint16_t normalize16(uint16_t u);
		/// @brief convert a 32 bit integer into little endian based on `util::endian`
		uint32_t normalize32(uint32_t u);
	}
}