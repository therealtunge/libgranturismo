#include <gpb/gpbBase.hpp>
#include <util/streams.hpp>
#define GPB2_HEADERSIZE 0x10
#define GPB2_ENTRYSIZE 0x10
namespace libgranturismo {
	/// @brief implementation of GPB2
	/// @details used in GT3 and partially in GT4
	class gpb2 : public gpbBase {
	public:
		/// @brief "GPB2", magic number for GPB2 (little endian)
		static const uint32_t magic = 0x32627067; // "GBP2"
		/// @brief "2BPG", alternative magic number for GPB2 (little endian)
		static const uint32_t magic_alt = 0x67706232; // "2PBG" (big endian)
		/// @brief read GPB2 file from a filename
		/// @param filename name of the file to read from
		/// @param endian endianness of the format, 0 for little, 1 for big
		int read(std::string filename, int endian) override;
	};
}
