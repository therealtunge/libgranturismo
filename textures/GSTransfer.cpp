#include <textures/GSTransfer.hpp>

using namespace libgranturismo;

void GSTransfer::read(std::ifstream *s) {
	BP = util::readUint16(s);
	BW = util::readUint8(s);
	format = (SCE_GS_PSM)util::readUint8(s);
	util::skip(s, 4);
	width = util::readUint16(s);
	height = util::readUint16(s);
	data = new uint8_t[width * height * 4]; // todo: dont use 4
	s->read((char*)data, width * height * 4);
}