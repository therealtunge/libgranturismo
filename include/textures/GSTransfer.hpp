#pragma once
#include <stdint.h>
#include <textures/GSStructs.hpp>
namespace libgranturismo {
	class GSTransfer {
	public:
		uint8_t BP;
		uint8_t BW;
		SCE_GS_PSM format;
		uint16_t width;
		uint16_t height;
		uint8_t *data;
		void read(std::ifstream *s);
	};
}