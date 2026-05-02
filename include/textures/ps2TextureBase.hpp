#include <string>
#include <fstream>
#include <util/streams.hpp>
#include <stdint.h>

namespace libgranturismo {
	/// @brief base for all textures used in PS2 GTs
	class ps2TextureBase {
		// TODO
	public:
		/// @brief read this type of PS2 texture from an ifstream (not a filename!)
		/// @param i the std::ifstream to read from. not a filename because textures can be packed into other formats thus requiring passing in the stream
		virtual int read(std::ifstream *i) = 0;
	};
}

