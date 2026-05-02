// implementation of textureset1 (or Tex1)
#include <textures/textureSet1.hpp>
using namespace libgranturismo;

int textureSet1::read(std::ifstream *s) {
	libgranturismo_unimpl("textureset1");
	/*
	int base_position = s->tellg();
	uint32_t m = util::readUint32(s);
	if (m != textureSet1::magic) {
		std::cerr << "tex1: invalid magic" << std::endl; 
		std::cerr << "expected: 0x" << std::hex << textureSet1::magic << " got: 0x" << m << std::endl;
		return 1;
	}
	util::skip(s, 8); // we dont use the reloc ptr and the empty uint32
	uint32_t textureSetSize = util::readUint32(s);
	util::skip(s, 2); // we dont use baseTbp
	uint16_t totalBlockSize = util::readUint16(s);
	uint16_t pgluTextureCount = util::ReadUint16(s);
	uint16_t textureInfoCount = util::ReadUint16(s);
	uint32_t pgluTextureMapOffset = util::readUint32(s);
	uint32_t textureInfosOffset = util::readUint32(s);
	uint32_t clutPatchesOffset = util::readUint32(s);

	s->seekg(base_position + pgluTextureMapOffset);
	for (int i = 0; i < pgluTextureCount; i++) {
		// TODO: implement this
	}

	return 0;*/
}