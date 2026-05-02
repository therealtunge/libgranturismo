// implementation of GPB version 2

#include <gpb/gpb3.hpp>

using namespace libgranturismo;

int gpb3::read(std::string filename, int endian) {
	
	std::ifstream p(filename);
	if (endian) {util::endian = libgranturismo::util::ENDIAN_BIG;}
	uint32_t m = util::readUint32(&p);
	
	if (m != gpb3::magic) {
		std::cerr << "gpb3: invalid magic" << std::endl; 
		std::cerr << "expected: 0x" << std::hex << gpb3::magic << " got: 0x" << m << std::endl;
		return 1;
	}

	util::skip(&p, 8); // relocation ptr & header size
	
	int entryCount = util::readUint32(&p);
	int entriesOffset = util::readUint32(&p);

	for (int i = 0; i < entryCount; i++)
	{
		p.seekg(entriesOffset + (i * GPB3_ENTRYSIZE));

		uint32_t fileNameOffset = util::readUint32(&p);
		uint32_t fileDataOffset = util::readUint32(&p);
		uint32_t fileSize = util::readUint32(&p);

		p.seekg(fileNameOffset);
		auto s = util::readString(&p);
		std::cout << s << " @ 0x" << std::hex << p.tellg() << std::endl;
		char *data = new char[fileSize];
		p.seekg(fileDataOffset);
		p.read(data, fileSize);
		auto *f = new gpbFile();
		f->filename = s;
		f->data = data;
		f->length = fileSize;
		files.push_back(f);
	}
	return 0; // all ok
}