#include <textures/ps2TextureBase.hpp>
#include <cstdlib>

using namespace libgranturismo;

void ps2TextureBase::initGSmem() {
	gsMemory = new uint32_t[1024*1024];
	for (int i = 0; i < 1; i++) {
		auto t = GSTransfers[i];
		switch (t->format) {
			case SCE_GS_PSMCT32: {
				GSMemory::writePSMCT32tex(gsMemory, t->BP, t->BW, 0, 0, t->width, t->height, (uint32_t*)t->data, 0);
				break;
			}
			default:
				return;
		}
	}
	return;
}