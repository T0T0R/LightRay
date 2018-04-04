#include "lightray.h"


LightRay::LightRay(float const& i, std::vector<float> const& colorRGB, std::vector<float> const& pos, std::vector<float> const& dir):
	intensity(i), RGB(colorRGB), position(pos), direction(dir)
{
	nbBumps = 0;
}

LightRay::~LightRay()
{
	//dtor
}
