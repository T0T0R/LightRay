#include "plane.h"

using namespace std;

Plane::Plane(vector<float> const& color, vector<std::vector<float> > const& points):
	RGB(color)
{
	//ctor
}

Plane::Plane(vector<float> const& color, vector<float> const& normalPlane, vector<float> const& point):
	RGB(color), normalToPlane(normalPlane), refPoint(point)
{
	//ctor
}

Plane::~Plane()
{
	//dtor
}


/***** ACCESSORS *****/
vector<float> Plane::getRGB(){
	return RGB;
}


/***** METHODS *****/
vector<float> calcNormal(vector<vector<float> > points){

