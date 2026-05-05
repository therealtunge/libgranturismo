#pragma once
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

	typedef enum {
		SCE_GS_NEAREST = 0,
		SCE_GS_LINEAR = 1,
		SCE_GS_NEAREST_MIPMAP_NEAREST = 2,
		SCE_GS_NEAREST_MIPMAP_LINEAR = 3,
		SCE_GS_LINEAR_MIPMAP_NEAREST = 4,
		SCE_GS_LINEAR_MIPMAP_LINEAR = 5,
	} SCE_GS_MAG;

	typedef enum {
		SCE_GS_REPEAT = 0,
		SCE_GS_CLAMP = 1,
		SCE_GS_REGION_CLAMP = 2,
		SCE_GS_REGION_REPEAT = 3,
	} SCE_GS_CLAMP_PARAMS;

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
	
	class sceGsTex1 {
	public:
		uint64_t LCM_LightColorMatrix;
		uint64_t pad01;
		uint64_t MXL_MaximumMIPLevel;
		SCE_GS_MAG MMAG;
		SCE_GS_MAG MMIN;
		uint64_t MTBA_unknown;
		uint64_t L;
		uint64_t K;
		void read(std::ifstream *stream, unsigned int bitoff);
		void write(std::ofstream *stream, unsigned int bitoff);
	};

	class sceGsMiptbp1 {
	public:
		uint64_t tbp1;
		uint64_t tbw1;
		uint64_t tbp2;
		uint64_t tbw2;
		uint64_t tbp3;
		uint64_t tbw3;
		void read(std::ifstream *stream, unsigned int bitoff);
		void write(std::ofstream *stream, unsigned int bitoff);
	};

	class sceGsMiptbp2 {
	public:
		uint64_t tbp4;
		uint64_t tbw4;
		uint64_t tbp5;
		uint64_t tbw5;
		uint64_t tbp6;
		uint64_t tbw6;
		void read(std::ifstream *stream, unsigned int bitoff);
		void write(std::ofstream *stream, unsigned int bitoff);
	};

	class sceGsClamp {
	public:
		SCE_GS_CLAMP_PARAMS wms;
		SCE_GS_CLAMP_PARAMS wmt;
		uint64_t minu;
		uint64_t maxu;
		uint64_t minv;
		uint64_t maxv;
		void read(std::ifstream *stream, unsigned int bitoff);
		void write(std::ofstream *stream, unsigned int bitoff);
	};
}