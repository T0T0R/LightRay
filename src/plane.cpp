#include "plane.h"

using namespace std;

Plane::Plane(vector<float> const& color, vector<std::vector<float> > const& points):
	RGB(color), refPoint(points[0]), refPoints(points)
{
	normalVector = calcNormal(points);
}


Plane::~Plane()
{
	//dtor
}


/***** ACCESSORS *****/
vector<float> Plane::getRGB(){
	return RGB;
}

vector<float> Plane::getNormal(){
	return normalVector;
}

std::vector<std::vector<float> > Plane::getPoints(){
	return refPoints;
}

/***** METHODS *****/
vector<float> Plane::calcNormal(vector<vector<float> > const& points){
	//Vectors definitions:
	float U[3];
	float V[3];
	U[0] = points[0][0] - points[1][0];
	U[1] = points[0][1] - points[1][1];
	U[2] = points[0][2] - points[1][2];
	V[0] = points[2][0] - points[1][0];
	V[1] = points[2][1] - points[1][1];
	V[2] = points[2][2] - points[1][2];

	//Normal vector:
	vector<float> normal(3);

	//Vector product
	normal[0] = ( U[1]*V[2]-U[2]*V[1] );
	normal[1] = ( U[2]*V[0]-U[0]*V[2] );
	normal[2] = ( U[0]*V[1]-U[1]*V[0] );

	normalize(normal);
	return normal;
}

vector<float> Plane::normalize(vector<float> & vec){
	float x = vec[0]/sqrt(pow(vec[0],2)+pow(vec[1],2)+pow(vec[2],2));
	float y = vec[1]/sqrt(pow(vec[0],2)+pow(vec[1],2)+pow(vec[2],2));
	float z = vec[2]/sqrt(pow(vec[0],2)+pow(vec[1],2)+pow(vec[2],2));
	vec[0]=x;
	vec[1]=y;
	vec[2]=z;
	return vec;
}

