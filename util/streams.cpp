#include <util/streams.hpp>

namespace libgranturismo {
	namespace util {
		// read a uint32, this handles endianness smartly
		uint32_t readUint32(std::ifstream *i) {
			uint32_t t;
			i->read((char*)&t, 4);
			return normalize32(t);
		}
		// read a uint16, this handles endianness smartly
		uint16_t readUint16(std::ifstream *i) {
			uint16_t t;
			i->read((char*)&t, 2);
			return normalize16(t);
		}
		// read a null-terminated string
		std::string readString(std::ifstream *i) {
			std::string s;
			char t = 1;
			while (t != 0) {
				i->read((char*)&t, 1);
				s += t;
			}
			return s;
		}
		// seek a stream forward without reading, useful for unknown bytes or ones unused in our code
		void skip(std::ifstream *i, std::streamoff e) {
			i->seekg(i->tellg() + e);
		}
	}
}