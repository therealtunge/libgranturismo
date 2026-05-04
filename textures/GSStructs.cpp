#include <textures/GSStructs.hpp>
#include <cinttypes>
// GS structs are bit packed, meaning horrible stupid stinky bit masking gotta happen... is what i would say if C didnt have bitpacked structs :)

using namespace libgranturismo;


typedef struct {
	uint64_t tbp0 : 14;
	uint64_t tbw : 6;
	SCE_GS_PSM psm : 6;
	uint64_t tw : 4;
	uint64_t th : 4;
	uint64_t tcc : 1;
	uint64_t tfx : 2;
	uint64_t cpb : 14;
	uint64_t cpsm : 4;
	uint16_t csm : 1;
	uint64_t csa : 5;
	uint64_t cld : 3;
} __attribute__((__packed__)) _scegstex0;

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
	printf("baby time %d %d %d\n", s.tbp0, s.tbw, s.psm);
}