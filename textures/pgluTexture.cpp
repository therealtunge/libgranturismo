#include <textures/pgluTexture.hpp>
#include <cstdio>
using namespace libgranturismo;

int pgluTexture::read(std::ifstream *i) {
	//char *registerData = new char[structSize];
	//i->read(registerData, structSize);
	tex0.read(i, 0);
	printf("%d %d %d\n", tex0.TW_TextureWidth, tex0.psm, i->tellg());
	//std::cout << << " " << i->tellg() << std::endl;
	return 0;
}
void pgluTexture::write(std::ostream *o) {

}