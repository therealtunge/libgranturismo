#pragma once
#include <string>
#include <fstream>
#include <stdint.h>
#include <vector>

#include <util/streams.hpp>
#include <textures/pgluTexture.hpp>
#include <textures/GSTransfer.hpp>
#include <textures/GSMemory.hpp>

namespace libgranturismo {
	/// @brief base for all textures used in PS2 GTs
	class ps2TextureBase {
		// TODO
	public:
		std::vector<pgluTexture*> pgluTextures;
		std::vector<GSTransfer*> GSTransfers;
		uint32_t *gsMemory;
		void initGSmem(); // NOT a interface function!
		/// @brief read this type of PS2 texture from an ifstream (not a filename!)
		/// @param i the std::ifstream to read from. not a filename because textures can be packed into other formats thus requiring passing in the stream
		virtual int read(std::ifstream *i) = 0;
	};
}

