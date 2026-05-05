#include <textures/pgluTexture.hpp>
#include <internal/GSStructs.hpp>

#include <cstdio>
using namespace libgranturismo;

pgluTexture::pgluTexture() {
	tex0 = new sceGsTex0();
	tex1 = new sceGsTex1();
	miptable1 = new sceGsMiptbp1();
	miptable2 = new sceGsMiptbp2();
}
/// @brief most screwed up function in this codebase
/// @details CALLING `PGLUTEXTURE::READ` AT 3 AM!!! (GONE SEGFAULT)
int pgluTexture::read(std::ifstream *i) {
	_pglutexture s;
	i->read((char*)&s, sizeof(_pglutexture));
	tex0->TBP0_TextureBaseAddress = s.tbp0;
	tex0->TBW_TextureBufferWidth  = s.tbw;
	tex0->psm = s.psm;
	tex0->TW_TextureWidth = s.tw;
	tex0->TH_TextureHeight = s.th;
	tex0->TCC_ColorComponent = s.tcc;
	tex0->TFX_TextureFunction = s.tfx;
	tex0->CBP_ClutBlockPointer = s.cpb;
	tex0->CPSM_ClutPartPixelFormatSetup = (SCE_GS_PSM)s.cpsm;
	tex0->CSM_ClutStorageMode = s.csm;
	tex0->CSA_ClutEntryOffset = s.csa;
	tex0->CLD_ClutBufferLoadControl = s.cld;
	
	tex1->LCM_LightColorMatrix = s.lcm;
	tex1->MXL_MaximumMIPLevel = s.mxl;
	tex1->MMAG = (SCE_GS_MAG)s.mmag;
	tex1->MMIN = s.mmin;
	tex1->L = s.l;
	tex1->K = s.k;

	miptable1->tbp1 = s.tbp1;
	miptable1->tbw1 = s.tbw1;
	miptable1->tbp2 = s.tbp2;
	miptable1->tbw2 = s.tbw2;
	miptable1->tbp3 = s.tbp3;
	miptable1->tbw3 = s.tbw3;

	miptable2->tbp4 = s.tbp4;
	miptable2->tbw4 = s.tbw4;
	miptable2->tbp5 = s.tbp5;
	miptable2->tbw5 = s.tbw5;
	miptable2->tbp6 = s.tbp6;
	miptable2->tbw6 = s.tbw6;
	return 0;
}
void pgluTexture::write(std::ostream *o) {

}