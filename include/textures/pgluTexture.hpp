#pragma once
#include <fstream>

#include <textures/GSStructs.hpp>

namespace libgranturismo {
	class pgluTexture {
	public:
		sceGsTex0 tex0;
		const int structSize = 0x28;
		int read(std::ifstream *i);
		void write(std::ostream *o);
	};
}