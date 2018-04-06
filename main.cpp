#include <iostream>
#include <cmath>

#include "vector3.h"
#include "lightray.h"
#include "plane.h"

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

using namespace std;


int main()
{
    cout << "Hello world!" << endl;

    Vector3 X(0, 0, 0);
    Vector3 Y(1, 0, 0);
    Vector3 Z(1, 1, 0);
	vector<Vector3> points (3);
	points[0]=X;
	points[1]=Y;
	points[2]=Z;

	vector<float> color(3, 1);

	Plane MyPlane(color, points);

	Vector3 norm = MyPlane.getNormal();

	LightRay MyRay(color, X, Y);
	MyRay.debug();

	cout<< norm.x() << " ; " << norm.y() << " ; " << norm.z()<< endl;

    return 0;
}
