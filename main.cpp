#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <iostream>
#include <cmath>

#define ZERO 1E-7 //define near zero limit

#include "include/vector3.h"
#include "include/lightray.h"
#include "include/plane.h"

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

using namespace std;


int main()
{
    cout << "Hello world!" << endl;

    Vector3 O(0, 0, 0);
    Vector3 A(1, 0, 0);
    Vector3 B(1, 1, 0);
	vector<Vector3> points (3);
	points[0]=B;
	points[1]=A;
	points[2]=O;

	vector<float> color(3, 1);

	Plane MyPlane(color, points);
	MyPlane.debug();

	LightRay MyRay(color, Vector3(1,1,1), Vector3(0,0,-1));
	MyRay.debug();

	MyPlane.intersect(MyRay).debug();

    return EXIT_SUCCESS;
}
