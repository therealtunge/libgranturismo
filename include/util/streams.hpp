#pragma once
#include <fstream>
#include <string>
#include <stdint.h>
#include <iostream>
#include <util/endian.hpp>

namespace libgranturismo {
	namespace util {
		uint64_t readUint64(std::ifstream *i);
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
		void writeUint8(std::ofstream *o, uint8_t u);
		void writeUint16(std::ofstream *o, uint16_t u);
		void writeUint32(std::ofstream *o, uint32_t u);
		void writeString(std::ofstream *o, std::string u);
	}
}