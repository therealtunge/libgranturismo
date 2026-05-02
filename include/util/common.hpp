#include <cstdlib>
#include <cassert>
#include <iostream>
#define libgranturismo_unimpl(name) std::cerr << name << ": unimplemented @ " << __FILE__ << ":" << __LINE__ << std::endl; abort();