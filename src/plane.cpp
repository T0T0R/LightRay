#include "plane.h"

Plane::Plane(std::vector<float> const& color, std::vector<std::vector<float> > const& points):
	RGB(color)
{
	//ctor
}

Plane::Plane(std::vector<float> const& color, std::vector<float> const& normalPlane, std::vector<float> const& point):
	RGB(color), normalToPlane(normalPlane), refPoint(point)
{
	//ctor
}

Plane::~Plane()
{
	//dtor
}
