#pragma once
#include <gpb/gpbBase.hpp>
#include <util/streams.hpp>
#include <util/common.hpp>
#define GPB3_HEADERSIZE 0x20
#define GPB3_ENTRYSIZE 0x10
namespace libgranturismo {
	/// @brief implementation of GPB3
	/// @details GPB version 3, used partially in gt4, and fully in PS3 games
	class gpb3 : public gpbBase {
	public:
		/// @brief "GPB3", magic number for GPB version 3, little endian
		static const uint32_t magic = 0x33627067;
		/// @brief "3BPG", magic number for GPB version 3, big endian
		static const uint32_t magic_alt = 0x67706233;
		/// @brief read GPB3 file from a filename
		/// @param filename name of the file to read from
		/// @param endian endianness of the format, 0 for little, 1 for big
		int read(std::string filename, int endian) override;
		int read(std::string filename) override;
		void write(std::string filename, int endian) override;
		void write(std::string filename) override;
	};
}
