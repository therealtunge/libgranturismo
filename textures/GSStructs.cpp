#include <textures/GSStructs.hpp>
#include <internal/GSStructs.hpp>
#include <cinttypes>
// GS structs are bit packed, meaning horrible stupid stinky bit masking gotta happen... is what i would say if C didnt have bitpacked structs :)

using namespace libgranturismo;

static_assert(sizeof(_scegstex0) == 8);

void sceGsTex0::read(std::ifstream *stream, unsigned int bitoff) {
	_scegstex0 s;
	stream->read((char*)&s, 8);
	TBP0_TextureBaseAddress = s.tbp0;
	TBW_TextureBufferWidth  = s.tbw;
	psm = s.psm;
	TW_TextureWidth = s.tw;
	TH_TextureHeight = s.th;
	TCC_ColorComponent = s.tcc;
	TFX_TextureFunction = s.tfx;
	CBP_ClutBlockPointer = s.cpb;
	CPSM_ClutPartPixelFormatSetup = (SCE_GS_PSM)s.cpsm;
	CSM_ClutStorageMode = s.csm;
	CSA_ClutEntryOffset = s.csa;
	CLD_ClutBufferLoadControl = s.cld;
	return;
}

void sceGsTex1::read(std::ifstream *stream, unsigned int bitoff) {
	_scegstex1 s;
	stream->read((char*)&s, sizeof(_scegstex1));
	LCM_LightColorMatrix = s.lcm;
	MXL_MaximumMIPLevel = s.mxl;
	MMAG = (SCE_GS_MAG)s.mmag;
	MMIN = s.mmin;
	L = s.l;
	K = s.k;
	return;
}

void sceGsMiptbp1::read(std::ifstream *stream, unsigned int bitoff) {
	_scegsmiptbp1 s;
	stream->read((char*)&s, sizeof(_scegsmiptbp1));
	tbp1 = s.tbp1;
	tbw1 = s.tbw1;
	tbp2 = s.tbp2;
	tbw2 = s.tbw2;
	tbp3 = s.tbp3;
	tbw3 = s.tbw3;
	return;
}

void sceGsMiptbp2::read(std::ifstream *stream, unsigned int bitoff) {
	_scegsmiptbp2 s;
	stream->read((char*)&s, sizeof(_scegsmiptbp1));
	tbp4 = s.tbp4;
	tbw4 = s.tbw4;
	tbp5 = s.tbp5;
	tbw5 = s.tbw5;
	tbp6 = s.tbp6;
	tbw6 = s.tbw6;
	return;
}

void sceGsClamp::read(std::ifstream *stream, unsigned int bitoff) {
	_scegsclamp s;
	stream->read((char*)&s, sizeof(_scegsclamp));
	wms = s.wms;
	wmt = s.wmt;
	minu = s.minu;
	maxu = s.maxu;
	minv = s.minv;
	maxv = s.maxv;
}