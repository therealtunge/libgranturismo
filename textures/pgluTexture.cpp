#include <textures/pgluTexture.hpp>
#include <cstdio>
using namespace libgranturismo;

int pgluTexture::read(std::ifstream *i) {
	tex0.read(i, 0);
	return 0;
}
void pgluTexture::write(std::ostream *o) {

}