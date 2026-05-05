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

typedef struct {
	uint64_t lcm : 1;
	uint64_t pad1 : 1;
	uint64_t mxl : 3;
	uint64_t mmag : 1; // sce_gs_mag
	SCE_GS_MAG mmin : 3;
	uint64_t mtba : 1;
	uint64_t unk0 : 9;
	uint64_t l : 2;
	uint64_t unk1 : 11;
	uint16_t k : 12;
	uint64_t unk2 : 20;
} __attribute__((__packed__)) _scegstex1;

typedef struct {
	uint64_t tbp1 : 14;
	uint64_t tbw1 : 6;
	uint64_t tbp2 : 14;
	uint64_t tbw2 : 6;
	uint64_t tbp3 : 14;
	uint64_t tbw3 : 6;
	uint64_t pad : 4;
} __attribute__((__packed__)) _scegsmiptbp1;

typedef struct {
	uint64_t tbp4 : 14;
	uint64_t tbw4 : 6;
	uint64_t tbp5: 14;
	uint64_t tbw5 : 6;
	uint64_t tbp6 : 14;
	uint64_t tbw6 : 6;
	uint64_t pad : 4;
} __attribute__((__packed__)) _scegsmiptbp2;

typedef struct {
	SCE_GS_CLAMP_PARAMS wms : 2;
	SCE_GS_CLAMP_PARAMS wmt : 2;
	uint64_t minu : 10;
	uint64_t maxu : 10;
	uint64_t minv : 10;
	uint64_t maxv : 10;
	uint64_t pad : 20;
} __attribute__((__packed__)) _scegsclamp;

typedef struct {
	//tex0
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
	//tex1
	uint64_t lcm : 1;
	uint64_t pad1 : 1;
	uint64_t mxl : 3;
	uint64_t mmag : 1; // sce_gs_mag
	SCE_GS_MAG mmin : 3;
	uint64_t mtba : 1;
	uint64_t unk0 : 9;
	uint64_t l : 2;
	uint64_t unk1 : 11;
	uint16_t k : 12;
	uint64_t unk2 : 20;
	//mip table 1
	uint64_t tbp1 : 14;
	uint64_t tbw1 : 6;
	uint64_t tbp2 : 14;
	uint64_t tbw2 : 6;
	uint64_t tbp3 : 14;
	uint64_t tbw3 : 6;
	uint64_t pad2 : 4;
	//mip table 2
	uint64_t tbp4 : 14;
	uint64_t tbw4 : 6;
	uint64_t tbp5: 14;
	uint64_t tbw5 : 6;
	uint64_t tbp6 : 14;
	uint64_t tbw6 : 6;
	uint64_t pad3 : 4;
	//gs clamp
	SCE_GS_CLAMP_PARAMS wms : 2;
	SCE_GS_CLAMP_PARAMS wmt : 2;
	uint64_t minu : 10;
	uint64_t maxu : 10;
	uint64_t minv : 10;
	uint64_t maxv : 10;
	uint64_t pad4 : 20;
} __attribute__((__packed__)) _pglutexture;

static_assert(sizeof(_scegstex0) == 0x8);
static_assert(sizeof(_scegstex1) == 0x8);
static_assert(sizeof(_scegsmiptbp1) == 0x8);
static_assert(sizeof(_scegsmiptbp2) == 0x8);
static_assert(sizeof(_scegsclamp) == 0x8);
static_assert(sizeof(_pglutexture) == 0x28);