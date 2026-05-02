#include <gpb/gpbBase.hpp>
#include <gpb/gpb2.hpp>
#include <gpb/gpb3.hpp>

namespace libgranturismo {
	std::unique_ptr<gpbBase> readGpbFromFile(std::string filename) {
		std::ifstream i(filename);
		uint32_t m = util::readUint32(&i);
		switch (m) {
			case (gpb2::magic): {
				auto g = std::make_unique<gpb2>();
				g->read(filename, 0);
				g->type = GPB2;
				return g;
			}
			case (gpb2::magic_alt): {
				auto g = std::make_unique<gpb2>();
				g->read(filename, 1);
				g->type = GPB2;
				return g;
			}
			case (gpb3::magic): {
				auto g = std::make_unique<gpb3>();
				g->read(filename, 0);
				g->type = GPB3;
				return g;
			}
			case (gpb3::magic_alt): {
				auto g = std::make_unique<gpb3>();
				g->read(filename, 1);
				g->type = GPB3;
				return g;
			}
			default: {
				std::cout << "null" << std::hex << m << std::endl;
				return nullptr;
			}
		}
	}
}