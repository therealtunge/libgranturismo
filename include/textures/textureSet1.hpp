#pragma once
#include <textures/ps2TextureBase.hpp>
#include <textures/pgluTexture.hpp>
#include <util/common.hpp>
namespace libgranturismo {
	class textureSet1 : public ps2TextureBase {
		static const int headerSize = 0x30;
		static const uint32_t magic = 0x31786554;
	public:
		int read(std::ifstream *s) override;
	};
}
