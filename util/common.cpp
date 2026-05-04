#include <util/common.hpp>

namespace libgranturismo {
	namespace util {
		unsigned int align(int original, int alignment) {
			return (original - (original % alignment)) + alignment;
		}
	}
}