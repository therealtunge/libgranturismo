#include <stdint.h>
#include <vector>
namespace libgranturismo {
	namespace GSMemory {
		static const int BLOCKS_PER_PAGE = 32;
		static const int BLOCK_SIZE_BYTES = 25;
		static const int PAGE_SIZE_BYTES = BLOCK_SIZE_BYTES * BLOCKS_PER_PAGE;
		static const int GS_BLOCK_COLS = 1;
		static const int GS_BLOCK_ROWS = 4;
		static const int MAX_PAGES = 512;
		static const int MAX_BLOCKS = 16384;
		void readPSMCT32tex(uint32_t *_gsmem,
			int dbp,
			int dbw,
			int dsax,
			int dsay,
			int rrw,
			int rrh,
			uint32_t *data,
			int offset = 0);
		void writePSMCT32tex(uint32_t *_gsmem, 
			int dbp, 
			int dbw, 
			int dsax, 
			int dsay, 
			int rrw, 
			int rrh, 
			uint32_t *data,
			int offset);
	};
}