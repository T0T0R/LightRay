#include "plane.h"

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

using namespace std;

Plane::Plane(vector<float> const& color, vector<vector<float> > const& points):
	RGB(color), refPoint(points[0]), refPoints(3)
{
	Vector3 A(points[0]);
	Vector3 B(points[1]);
	Vector3 C(points[2]);

	refPoints[0] = A;
	refPoints[1] = B;
	refPoints[2] = C;

	normalVector = calcNormal(refPoints);
}


Plane::Plane(vector<float> const& color, vector<Vector3> const& points):
	RGB(color), refPoint(points[0]), refPoints(points)
{
	normalVector = calcNormal(refPoints);
}


Plane::~Plane()
{
	//dtor
}




/***** ACCESSORS *****/
vector<float> Plane::getRGB(){
	return RGB;
}


Vector3 Plane::getNormal(){
	return normalVector;
}


Vector3 Plane::getPoint(){
	return refPoint;
}


vector<Vector3 > Plane::getPoints(){
	return refPoints;
}



/***** METHODS *****/
Vector3 Plane::calcNormal(vector<Vector3> & points){
	//Vectors definitions:
	Vector3 U( points[0].x()-points[1].x(), points[0].y()-points[1].y(), points[0].z()-points[1].z() );
	Vector3 V( points[2].x()-points[1].x(), points[2].y()-points[1].y(), points[2].z()-points[1].z() );

	//Normal vector:
	//Vector product
	Vector3 normal(U.y()*V.z()-U.z()*V.y(), U.z()*V.x()-U.x()*V.z(), U.x()*V.y()-U.y()*V.x());

	normal.normalize();
	return normal;
}


vector<float> Plane::getEquation(){
	vector<float> equation(4);
	equation[0] = normalVector.x();
	equation[1] = normalVector.y();
	equation[2] = normalVector.z();
	equation[3] = -1*( normalVector.x()*refPoint.x() +  normalVector.y()*refPoint.y() + normalVector.z()*refPoint.z());
	return equation;
}


Vector3 Plane::intersect(LightRay){	//TO DO

}


int Plane::reflect(LightRay & incidentRay){	//TO DO
	Vector3 incidentDir = incidentRay.getDirection();
	return 0;
}


int Plane::debug(){
	cout<<"[DEBUG - PLANE] - color:"<<RGB[0]<<";"<<RGB[1]<<";"<<RGB[2]<<
		" normal:"<<normalVector.x()<<";"<<normalVector.y()<<";"<<normalVector.z()<<
		" refPoint:"<<refPoint.x()<<";"<<refPoint.y()<<";"<<refPoint.z()<<endl;
	return 0;
}
