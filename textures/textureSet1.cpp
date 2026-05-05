// implementation of textureset1 (or Tex1)
#include <textures/textureSet1.hpp>
#include <textures/bitmap.hpp>


using namespace libgranturismo;

int textureSet1::read(std::ifstream *s) {

//	libgranturismo_unimpl("textureset1");
	uint32_t base_position = s->tellg();
	uint32_t m = util::readUint32(s);
	if (m != textureSet1::magic) {
		std::cerr << "tex1: invalid magic" << std::endl; 
		std::cerr << "expected: 0x" << std::hex << textureSet1::magic << " got: 0x" << m << std::endl;
		return 1;
	}
	uint32_t relocPtr = util::readUint32(s);
	uint32_t empty = util::readUint32(s);
	uint32_t fileSize = util::readUint32(s);
	uint16_t baseTbpOff = util::readUint16(s);
	uint16_t totalBlockSize = util::readUint16(s);
	uint16_t pgluTextureCount = util::readUint16(s);
	uint16_t transferCount = util::readUint16(s);
	uint32_t pgluTextureMapOff = util::readUint32(s);
	uint32_t transferInfosOff = util::readUint32(s);
	uint32_t clutPatchesOffset = util::readUint32(s);
	uint32_t clutAnimationOffset = util::readUint32(s);
	uint32_t unkOffset4 = util::readUint32(s);
	s->seekg(base_position + pgluTextureMapOff);
	for (int i = 0; i < pgluTextureCount; i++) {
		auto t = new pgluTexture();
		t->read(s);
		pgluTextures.push_back(t);
	}
	for (int i = 0; i < transferCount; i++) {
		auto g = new GSTransfer();
		s->seekg(base_position + transferInfosOff + (i * 12)); // 12 = sizeof(GSTransfer)
		g->read(s);
		GSTransfers.push_back(g);
	}
	initGSmem();
	auto t = GSTransfers[0];
	auto d = new uint32_t[t->width * t->height];
	GSMemory::readPSMCT32tex(gsMemory, pgluTextures[0]->tex0->TBP0_TextureBaseAddress, pgluTextures[0]->tex0->TBW_TextureBufferWidth, 0, 0, t->width, t->height, d);
	writeBMP(d, t->width, t->height, "test_assets/test.bmp");
	return 0;
}