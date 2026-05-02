#include <fstream>
#include <string>
#include <stdint.h>
#include <iostream>
#include <util/endian.hpp>

namespace libgranturismo {
	namespace util {
		/// @brief read a uint32_t from an ifstream
		/// @details set `util::endian` to define the current endianness and the function will comply automatically
		/// @param i the stream to read from
		uint32_t readUint32(std::ifstream *i);
		/// @brief read a uint16_t from an ifstream
		/// @details set `util::endian` to define the current endianness and the function will comply automatically
		/// @param i the stream to read from
		uint16_t readUint16(std::ifstream *i);
		/// @brief read a null-terminated from an ifstream
		/// @param i the stream to read from
		/// @return the read string
		std::string readString(std::ifstream *i);
		/// @brief skip (seek forward) e bytes from the i stream
		/// @param i the stream to seek forward
		/// @param e the amount of bytes to skip
		void skip(std::ifstream *i, std::streamoff e);
	}
}