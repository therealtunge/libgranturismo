// not actually a bitmap for the PS2, but just windows bitmap output to convert textures
#include <string>
#include <stdint.h>
//#include <winbitmap.hpp>
namespace libgranturismo {
	void writeBMP(uint32_t *data, int width, int height, std::string filename) {
	/*	winbitmap::canvas canvas(width,height);
		
		for (int i = 0; i < width * height; i++) {
			canvas.set_color(data[i] & 0xFF, data[i] & 0xFF00 >> 8, data[i] & 0xFF0000 >> 16);
			canvas.draw_point(i % width, i / width);
		}
		canvas.save_to_file("test_assets/test.bmp");*/
	}
}
