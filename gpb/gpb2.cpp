// implementation of GPB version 2

#include <gpb/gpb2.hpp>

using namespace libgranturismo;
void gpb2::write(std::string filename) {
	write(filename, 0);
}
int gpb2::read(std::string filename) {
	return read(filename, 0);
}
void gpb2::write(std::string filename, int endian = 0) {
	std::ofstream p(filename);

	if (endian) {util::endian = libgranturismo::util::ENDIAN_BIG;}

	util::writeUint32(&p, gpb2::magic); // magic
	util::writeUint32(&p, 0); // reloc ptr
	util::writeUint32(&p, GPB2_HEADERSIZE); // header size
	util::writeUint32(&p, files.size()); // file count

	int baseFileNameOffset = GPB2_HEADERSIZE + (GPB2_ENTRYSIZE * files.size());
	int currentFileNameOffset = baseFileNameOffset;

	for (unsigned int i = 0; i < files.size(); i++)	
	{
		p.seekp(GPB2_HEADERSIZE + (i * GPB2_ENTRYSIZE));
		util::writeUint32(&p, currentFileNameOffset);

		p.seekp(currentFileNameOffset);
		util::writeString(&p, files[i]->filename);
		currentFileNameOffset = (int)p.tellp();
	}

	int baseDataOffset = (int)p.tellp();
	int currentFileDataOffset = baseDataOffset;

	for (unsigned int i = 0; i < files.size(); i++)
	{
		p.seekp(GPB2_HEADERSIZE + (i * GPB2_ENTRYSIZE) + 4);
		util::writeUint32(&p, currentFileDataOffset);
		util::writeUint32(&p, files[i]->length);

		p.seekp(currentFileDataOffset);
		p.write(files[i]->data, files[i]->length);

		currentFileDataOffset = (int)p.tellp();
	}
}

int gpb2::read(std::string filename, int endian) {
	std::ifstream p(filename);
	uint32_t m = util::readUint32(&p);
	if (endian) {util::endian = libgranturismo::util::ENDIAN_BIG;}
	if (m != gpb2::magic) {
		std::cerr << "gpb2: invalid magic" << std::endl; 
		std::cerr << "expected: 0x" << std::hex << gpb2::magic << " got: 0x" << m << std::endl;
		return 1;
	}

	util::skip(&p, 8); // relocation ptr
	//int headerSize = util::readUint32(&p); // Empty
	int entryCount = util::readUint32(&p);

	for (int i = 0; i < entryCount; i++)
	{
		p.seekg(GPB2_HEADERSIZE + (i * GPB2_ENTRYSIZE));

		uint32_t fileNameOffset = util::readUint32(&p);
		uint32_t fileDataOffset = util::readUint32(&p);
		uint32_t fileSize = util::readUint32(&p);

		p.seekg(fileNameOffset);
		auto s = util::readString(&p);
	//	std::cout << s << " @ 0x" << std::hex << p.tellg() << std::endl;
		char *data = new char[fileSize];
		p.seekg(fileDataOffset);
		p.read(data, fileSize);
		auto *f = new gpbFile();
		f->filename = s;
		f->data = data;
		f->length = fileSize;
		files.push_back(f);
	}
	util::endian = libgranturismo::util::ENDIAN_LITTLE;
	return 0; // all ok
}