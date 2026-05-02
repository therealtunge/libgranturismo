#include <stdint.h>
#include <util/endian.hpp>

namespace libgranturismo {
	namespace util {
		endianness endian = ENDIAN_LITTLE;
		uint16_t normalize16(uint16_t u) {
			if (endian == ENDIAN_BIG) {return ((u & 0xff) << 8) | ((u & 0xff00) >> 8);} else {return u;}
		}
		uint32_t normalize32(uint32_t u) {
			if (endian == ENDIAN_BIG) {
				return ( (u & 0xFF) << 24 ) |
					( ((u >> 8) & 0xFF) << 16 ) |
					( ((u >> 16) & 0xFF) << 8 ) |
					(u >> 24);

			} else {return u;}
		}
	}
}