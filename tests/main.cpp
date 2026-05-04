#include <libgranturismo.hpp>
#include <textures/textureSet1.hpp>
#include <iomanip>
#include <crc32.hpp>
#include <cstring>
#include <unistd.h>
#include <iterator>
#include <filesystem>
#define TOTAL_TESTS 4
#define CRC32_GPB2_PACKING_TEST 0x1634bdc4 // crc32 for test_assets/inputs/gpb2_test.gpb
#define CRC32_GPB3_PACKING_TEST 0x2d287a2f // crc32 for test_assets/inputs/gpb3_test.gpb
int passed = 0;
int failed = 0;

std::string cur_test;
static inline bool TEST_FILE(uint32_t t, std::string v) { 
	uint32_t crc = 0xFFFFFFFF;
	std::ifstream f(v);
	std::noskipws(f);
	std::istream_iterator<uint8_t> head(f), tail;
	crc = crc32<IEEE8023_CRC32_POLYNOMIAL>(crc, head, tail);

	return crc == t;
}
#define TEST_ASSERT(b, c) if (!(b)) {std::cerr << cur_test << " : " << c << std::endl; return 1;}
#define TEST(b, c) if(b()) { \
				std::cerr << c << "\033[31m" << "\t\tFAIL" << "\033[37m" <<std::endl; \
				failed++; \
			} \
			else { \
				std::cerr << c << "\033[32m" << "\t\tPASS" << "\033[37m" << std::endl; \
				passed++;\
			}

static int gpb2_pack() {
	cur_test = "gpbv2 packing";
	auto g = new libgranturismo::gpb2();

	g->files = libgranturismo::loadGpbFileVectorFromDirectory("test_assets/inputs/gpb_test");
	TEST_ASSERT(g->files.size() == 1, "incorrect file count");
	auto file = g->files[0];
	TEST_ASSERT(file->length == strlen("this is a test :)"), "internal exception: incorrect file length"); // should never fail
	g->write("test_assets/temp/gpb2_test.gpb");
//	TEST_ASSERT(TEST_FILE(CRC32_GPB2_PACKING_TEST, "test_assets/temp/gpb2_test.gpb"), "incorrect file data");
	return 0;
}

static int gpb2_unpack() {
	cur_test = "gpbv2 unpacking";
	auto g = new libgranturismo::gpb2();
	g->read("test_assets/inputs/gpb2_test.gpb");
	auto file = g->files[0];
	TEST_ASSERT(g->files.size() == 1, "incorrect file size");
	TEST_ASSERT(file->length == strlen("this is a test :)"), "incorrect file length");
	TEST_ASSERT(strcmp(file->data, "this is a test :)") == 0, "incorrect file data");
	return 0;
}

static int gpb3_unpack() {
	cur_test = "gpbv3 unpacking";
	auto g = new libgranturismo::gpb3();
	g->read("test_assets/inputs/gpb3_test.gpb");
	auto file = g->files[0];
	TEST_ASSERT(g->files.size() == 1, "incorrect file size");
	TEST_ASSERT(file->length == strlen("this is a test :)"), "incorrect file length");
//	TEST_ASSERT(strcmp(file->data, "this is a test :)") == 0, "incorrect file data");
	return 0;
}
static int gpb3_pack() {
	cur_test = "gpbv3 packing";
	auto g = new libgranturismo::gpb3();

	g->files = libgranturismo::loadGpbFileVectorFromDirectory("test_assets/inputs/gpb_test/test");
	TEST_ASSERT(g->files.size() == 1, "incorrect file count");
	auto file = g->files[0];
	TEST_ASSERT(file->length == strlen("this is a test :)"), "internal exception: incorrect file length"); // should never fail
	g->write("test_assets/temp/gpb3_test.gpb");
	TEST_ASSERT(TEST_FILE(CRC32_GPB3_PACKING_TEST, "test_assets/temp/gpb3_test.gpb"), "incorrect file data");
	return 0;
}

void print_stats() {
	std::cout << "========================================" << std::endl;
	if (failed >= 1) {
		std::cout << "\033[31m" << "FAILED" << " : " << failed << "/" << TOTAL_TESTS << std::endl; // red
		std::cout << "\033[31m" << "PASSED" << " : " << passed << "/" << TOTAL_TESTS << std::endl; // red
	} else {
		std::cout << "\033[32m" << "FAILED" << " : " << failed << "/" << TOTAL_TESTS << std::endl; // green
		std::cout << "\033[32m" << "PASSED" << " : " << passed << "/" << TOTAL_TESTS << std::endl; // green
	}
	std::cout << "\033[37m"; // white
	std::cout << "========================================" << std::endl;
}

int main(int argc, char **argv)
{
	//TEST(gpb2_unpack, "gpbv2 unpacking");
	//TEST(gpb2_pack, "gpbv2 packing");
	// no need for gpb2 validity check, test_assets/temp/gpb2_test.gpb loads in GT4 (loads = doesnt crash the game) but i cant test loading files off it
	//TEST(gpb3_unpack, "gpbv3 unpacking");
	//TEST(gpb3_pack, "gpbv3 packing");
	// no need for gpb3 validity check, test_assets/temp/gpb3_test.gpb loads in GT4 (loads = doesnt crash the game) but i cant test loading files off it
	std::cout << std::filesystem::current_path() << std::endl;
	std::ifstream st("/home/behrad/Desktop/vol_extracted/loading.img");
	auto t = new libgranturismo::textureSet1();
	t->read(&st);
	print_stats();
	uint32_t crc = 0xFFFFFFFF;
	std::ifstream f("test_assets/temp/gpb3_test.gpb");
	std::noskipws(f);
	std::istream_iterator<uint8_t> head(f), tail;
	crc = crc32<IEEE8023_CRC32_POLYNOMIAL>(crc, head, tail);

	std::cout << std::hex;
	std::cout << std::showbase;
	std::cout << std::setw(8);
	std::cout << std::setfill('0');
	std::cout << crc << std::endl;
}