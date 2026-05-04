#include <util/streams.hpp>

namespace libgranturismo {
	namespace util {
		// read a uint64, this doesnt handle endianness
		uint64_t readUint64(std::ifstream *i) {
			uint64_t t;
			i->read((char*)&t, 8);
			return t;
		}
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
		void writeUint32(std::ofstream *o, uint32_t u) {
			uint32_t h = normalize32(u);
			o->write((const char*)&h, 4);
		}
		void writeUint16(std::ofstream *o, uint16_t u) {
			uint32_t h = normalize16(u);
			o->write((const char*)&h, 2);
		}
		void writeUint8(std::ofstream *o, uint8_t u) {
			o->write((const char*)&u, 1);
		}
		void writeString(std::ofstream *o, std::string u) {
			o->write(u.c_str(), u.size() + 1);
		}
		// seek a stream forward without reading, useful for unknown bytes or ones unused in our code
		void skip(std::ifstream *i, std::streamoff e) {
			i->seekg(i->tellg() + e);
		}
	}
}