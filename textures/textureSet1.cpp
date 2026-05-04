// implementation of textureset1 (or Tex1)
#include <textures/textureSet1.hpp>
using namespace libgranturismo;

int textureSet1::read(std::ifstream *s) {

//	libgranturismo_unimpl("textureset1");
	uint32_t base_position = s->tellg();
	uint32_t m = util::readUint32(s);
	printf("%d ABABABN\n", s->tellg());
	if (m != textureSet1::magic) {
		std::cerr << "tex1: invalid magic" << std::endl; 
		std::cerr << "expected: 0x" << std::hex << textureSet1::magic << " got: 0x" << m << std::endl;
		return 1;
	}
	uint32_t relocPtr = util::readUint32(s);
	printf("%d ABABABN\n", s->tellg());
	uint32_t empty = util::readUint32(s);
	printf("%d ABABABN\n", s->tellg());
	uint32_t fileSize = util::readUint32(s);
	printf("%d ABABABN\n", s->tellg());
	uint16_t baseTbpOff = util::readUint16(s);
	printf("%d ABABABN\n", s->tellg());
	uint16_t totalBlockSize = util::readUint16(s);
	printf("%d ABABABN\n", s->tellg());
	uint16_t pgluTextureCount = util::readUint16(s);
	printf("%d ABABABN\n", s->tellg());
	uint16_t transferCount = util::readUint16(s);
	printf("%d ABABABN\n", s->tellg());
	uint32_t pgluTextureMapOff = util::readUint32(s);
	printf("%d ABABABN\n", s->tellg());
	uint32_t transferInfosOff = util::readUint32(s);
	printf("%d ABABABN\n", s->tellg());
	uint32_t clutPatchesOffset = util::readUint32(s);
	printf("%d ABABABN\n", s->tellg());
	uint32_t clutAnimationOffset = util::readUint32(s);
	printf("%d ABABABN\n", s->tellg());
	uint32_t unkOffset4 = util::readUint32(s);
	printf("%d AAAA\n", s->tellg());
	s->seekg(base_position + pgluTextureMapOff);
	printf("%d AASVAAA\n", s->tellg());
	for (int i = 0; i < pgluTextureCount; i++) {
		auto t = new pgluTexture();
		t->read(s);
		pgluTextures.push_back(t);
	}
	return 0;
}