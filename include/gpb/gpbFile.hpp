#include <string>
namespace libgranturismo {
	/// @brief represents a file in a gpb
	/// @details used in the `files` array of a gpbBase
	class gpbFile {
	public:
		std::string filename;
		char *data;
		int length;
	};
}
