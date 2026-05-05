#include <textures/GSMemory.hpp>
#include <cstdio>
using namespace libgranturismo;
int BlockLayout[32] = {		
	0,  1,  4,  5, 16, 17, 20, 21,
	2,  3,  6,  7, 18, 19, 22, 23,
	8,  9, 12, 13, 24, 25, 28, 29,
	10, 11, 14, 15, 26, 27, 30, 31
};

int columnWord32[16] = {
	0,  1,  4,  5,  8,  9, 12, 13,
	2,  3,  6,  7, 10, 11, 14, 15
};

void GSMemory::readPSMCT32tex(uint32_t *_gsmem, int dbp, int dbw, int dsax, int dsay, int rrw, int rrh, uint32_t *data, int offset) {
	int startBlockPos = dbp * 64;
	int idx = 0;
	for (int y = dsay; y < dsay + rrh; y++) {
		for (int x = dsax; x < dsax + rrw; x++) {
			int pageX = x / 64;
			int pageY = y / 32;
			int page = pageX + pageY * dbw;

			int px = x - (pageX * 64);
			int py = y - (pageY * 32);

			int blockX = px / 8;
			int blockY = py / 8;
			int block = BlockLayout[blockX + blockY * 8];

			int bx = px - blockX * 8;
			int by = py - blockY * 8;

			int column = by / 2;

			int cx = bx;
			int cy = by - column * 2;
			int cw = columnWord32[cx + cy * 8];

			data[idx] = _gsmem[(startBlockPos + page * 2048 + block * 64 + column * 16 + cw) + (offset / sizeof(int))];
			idx++;
		}
	}
}
void GSMemory::writePSMCT32tex(uint32_t *_gsmem, int dbp, int dbw, int dsax, int dsay, int rrw, int rrh, uint32_t *data, int offset) {
	int startBlockPos = dbp * 64;
	int idx = 0;
	for (int y = dsay; y < dsay + rrh; y++) {
		for (int x = dsax; x < dsax + rrw; x++) {
			int pageX = x / 64;
			int pageY = y / 32;

			int page = pageX + pageY * dbw;

			int px = x - (pageX * 64);
			int py = y - (pageY * 32);

			int blockX = px / 8;
			int blockY = py / 8;
			int block =	BlockLayout[blockX + blockY * 8];

			int bx = px - blockX * 8;
			int by = py - blockY * 8;

			int column = by / 2;

			int cx = bx;
			int cy = by - column * 2;
			int cw = columnWord32[cx + cy * 8];
			printf("%u adn bagvbsdgzazsgvb\n", data[idx]);
			_gsmem[(startBlockPos + page * 2048 + block * 64 + column * 16 + cw) + (offset / sizeof(int))] = data[idx];
			idx++;
		}
	}
}