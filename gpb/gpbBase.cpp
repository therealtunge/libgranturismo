#include <gpb/gpbBase.hpp>
#include <gpb/gpb2.hpp>
#include <gpb/gpb3.hpp>
#include <filesystem> 
#include "unistd.h"

static std::vector<std::string> get_all_paths(const std::string& dir_path) {
	std::vector<std::string> paths;
	for (const auto& entry : std::filesystem::recursive_directory_iterator(dir_path)) {
		if (entry.path().string() == "." || entry.path().string() == "..") {
			continue;
		}
		if (std::filesystem::is_regular_file(entry.path())) {
			paths.push_back(std::filesystem::relative(entry.path(), dir_path).string());
		}
	}
	return paths;
}
namespace libgranturismo {
	std::vector<gpbFile*> loadGpbFileVectorFromDirectory(std::string dirName) {
		std::vector<gpbFile*> ret;
		for (auto i : get_all_paths(dirName)) {
			auto temp = new gpbFile();
			auto f = std::filesystem::file_size(dirName + "/" + i);
			std::ifstream t(dirName + "/" + i);
			auto d = new char[f];
			temp->filename = "/" + i;
			t.read(d, f);
			temp->data = d;
			temp->length = f;
			t.close();
			ret.push_back(temp);
		}
		return ret;
	}
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