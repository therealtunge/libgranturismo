// implementation of GPB version 2

#include <gpb/gpb3.hpp>

using namespace libgranturismo;
void gpb3::write(std::string filename) {
	write(filename, 1);
}
void gpb3::write(std::string filename, int endian) {
	std::ofstream p(filename);
	if (endian) {util::endian = libgranturismo::util::ENDIAN_BIG;}

	util::writeUint32(&p, gpb3::magic);
	util::writeUint32(&p, 0);
	util::writeUint32(&p, GPB3_HEADERSIZE);
	util::writeUint32(&p, files.size());
	int baseFileNameOffset = GPB3_HEADERSIZE + (GPB3_ENTRYSIZE * files.size());
	int currentFileNameOffset = baseFileNameOffset;

	for (unsigned int i = 0; i < files.size(); i++) {
		p.seekp(GPB3_HEADERSIZE + (i * GPB3_ENTRYSIZE));
		util::writeUint32(&p, currentFileNameOffset);

		p.seekp(currentFileNameOffset);
		util::writeString(&p, files[i]->filename);
		currentFileNameOffset = (int)p.tellp();
    }

	unsigned int align = util::align(p.tellp(), 0x80);
	for (unsigned int i = p.tellp(); i < align; i++) {
		util::writeUint8(&p, 0x5E);
	}

	int baseDataOffset = (int)p.tellp();
	int currentFileDataOffset = baseDataOffset;

	for (unsigned int i = 0; i < files.size(); i++) {
		p.seekp(GPB3_HEADERSIZE + (i * GPB3_ENTRYSIZE) + 4);
		util::writeUint32(&p, currentFileDataOffset);
		util::writeUint32(&p, files[i]->length);

		p.seekp(currentFileDataOffset);
		p.write(files[i]->data, files[i]->length);
		align = util::align(p.tellp(), 0x80);
		for (unsigned int j = p.tellp(); j < align; j++) {
			util::writeUint8(&p, 0x5E);
		}
		currentFileDataOffset = (int)p.tellp();
	}
	p.seekp(0x10);
	util::writeUint32(&p, GPB3_HEADERSIZE); // Offset of entries
	util::writeUint32(&p, baseFileNameOffset);
	util::writeUint32(&p, baseDataOffset);
}
int gpb3::read(std::string filename) {
	return read(filename, 1);
}
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