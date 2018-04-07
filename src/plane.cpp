#include "../include/plane.h"

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


Plane::Plane(vector<float> const& color, vector<float> const& eq):
	RGB(color), normalVector(eq[0], eq[1], eq[2])
{

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
vector<float> Plane::getRGB() const{
	return RGB;
}


Vector3 Plane::getNormal() const{
	return normalVector;
}


Vector3 Plane::getPoint() const{
	return refPoint;
}


vector<Vector3 > Plane::getPoints() const{
	return refPoints;
}



/***** METHODS *****/
Vector3 Plane::calcNormal(vector<Vector3> const& points){
	//Vectors definitions:
	Vector3 U( points[0].x()-points[1].x(), points[0].y()-points[1].y(), points[0].z()-points[1].z() );
	Vector3 V( points[2].x()-points[1].x(), points[2].y()-points[1].y(), points[2].z()-points[1].z() );

	//Normal vector:
	//Vector product
	Vector3 normal(U.product(V));

	normal.normalize();
	return normal;
}


vector<float> Plane::getEquation() const{
	vector<float> equation(4);
	equation[0] = normalVector.x();
	equation[1] = normalVector.y();
	equation[2] = normalVector.z();
	equation[3] = -1*( normalVector.x()*refPoint.x() +  normalVector.y()*refPoint.y() + normalVector.z()*refPoint.z());
	return equation;
}


Vector3 Plane::intersect(LightRay const& ray) const{
	/**	In case of no intersection, returns original position of ray.
	*/

	//Gathering parametric datas from objects
	Vector3 u(ray.getDirection());
	Vector3 pos(ray.getPosition());
	vector<float> plane(getEquation());

	//Ray parallel to plane:
	if (abs(u.x()*plane[0]+u.y()*plane[1]+u.z()*plane[2]) <= ZERO){	//E-7 : arbitrary limit near to zero
		cout<<"Ray parallel to plane, won\'t move!"<<endl;
		return pos;
	}else if (normalVector.scalar(u)>=0){	//ray is going to the opposite side of the plane
		cout<<"Ray opposite to plane, won\'t move!"<<endl;
		return pos;
	}else{
		//t : parameter of ray
		float t = -1* ( plane[0]*pos.x() + plane[1]*pos.y() + plane[2]*pos.z() + plane[3] ) /
			( u.x()*plane[0] + u.y()*plane[1] + u.z()*plane[2] );

		return Vector3( pos.x()+u.x()*t , pos.y()+u.y()*t , pos.x()+u.z()*t );
	}
}


int Plane::reflect(LightRay & incidentRay) const{	//TO DO
	Vector3 incidentDir = incidentRay.getDirection();
	return EXIT_SUCCESS;
}


int Plane::debug() const{
	cout<<"[DEBUG - PLANE] - color:"<<RGB[0]<<";"<<RGB[1]<<";"<<RGB[2]<<
		" normal:"<<normalVector.x()<<";"<<normalVector.y()<<";"<<normalVector.z()<<
		" refPoint:"<<refPoint.x()<<";"<<refPoint.y()<<";"<<refPoint.z()<<endl;
	return EXIT_SUCCESS;
}
