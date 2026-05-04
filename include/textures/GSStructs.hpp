#include <stdint.h>
#include <util/streams.hpp>
#include <util/common.hpp>

namespace libgranturismo {
	typedef enum {
		SCE_GS_PSMCT32 = 0,
		SCE_GS_PSMCT24 = 1,
		SCE_GS_PSMCT16 = 2,
		SCE_GS_PSMCT16S = 10,
		SCE_GS_PSMT8 = 19,
		SCE_GS_PSMT4 = 20,
		SCE_GS_PSMT8H = 27,
		SCE_GS_PSMT4HL = 36,
		SCE_GS_PSMT4HH = 44,
		SCE_GS_PSMZ32 = 48,
		SCE_GS_PSMZ24 = 49,
		SCE_GS_PSMZ16 = 50,
		SCE_GS_PSMZ16S = 58,
	} SCE_GS_PSM;
	class sceGsTex0 {
	public:
		uint16_t TBP0_TextureBaseAddress;
		uint8_t TBW_TextureBufferWidth;
		SCE_GS_PSM psm;
		uint8_t TW_TextureWidth;
		uint8_t TH_TextureHeight;
		uint8_t TCC_ColorComponent;
		uint64_t TFX_TextureFunction;
		uint16_t CBP_ClutBlockPointer;
		SCE_GS_PSM CPSM_ClutPartPixelFormatSetup;
		uint64_t CSM_ClutStorageMode;
		uint8_t CSA_ClutEntryOffset;
		uint64_t CLD_ClutBufferLoadControl;
		void read(std::ifstream *stream, unsigned int bitoff);
		void write(std::ofstream *stream, unsigned int bitoff);
	};
}