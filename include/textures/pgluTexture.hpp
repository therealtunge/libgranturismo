#pragma once
#include <fstream>

#include <textures/GSStructs.hpp>

namespace libgranturismo {
	class pgluTexture {
	public:
		sceGsTex0 *tex0;
		sceGsTex1 *tex1;
		sceGsMiptbp1 *miptable1;
		sceGsMiptbp2 *miptable2;
		const int structSize = 0x28;
		pgluTexture();
		int read(std::ifstream *i);
		void write(std::ostream *o);
	};
}