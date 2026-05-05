#include <string>
#include <fstream>

#include <stdint.h>

#include <util/streams.hpp>

#define BITMAP_HEADER 56
namespace libgranturismo {
	typedef struct {
		char bitmapSignatureBytes[2] = {'B', 'M'};
		uint32_t sizeOfBitmapFile;
		uint32_t reservedBytes;
		uint32_t pixelDataOffset;
	} bmpHeader;

	typedef struct {
		uint32_t sizeOfThisHeader;
		int32_t width;
		int32_t height;
		uint16_t numberOfColorPlanes = 1; // must be 1
		uint16_t colorDepth = 24;
		uint32_t compressionMethod;
		uint32_t rawBitmapDataSize;
		int32_t horizontalResolution;
		int32_t verticalResolution;
		uint32_t colorTableEntries;
		uint32_t importantColors;
	} __attribute__((__packed__)) bmpInfoHeader;

	void writeBMP(uint32_t *data, int width, int height, std::string filename);
}