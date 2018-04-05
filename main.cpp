#include <iostream>
#include <math.h>

#include "lightray.h"
#include "plane.h"

using namespace std;


int main()
{
    cout << "Hello world!" << endl;
    vector<float> X(3);
    X[0]=0;
    X[1]=0;
    X[2]=0;
    vector<float> Y(3);
    Y[0]=1.0;
    Y[1]=0;
    Y[2]=0;
    vector<float> Z(3);
    Z[0]=1.0;
	Z[1]=1.0;
    Z[2]=0;
	vector<vector<float> > points (3);
	points[0]=X;
	points[1]=Y;
	points[2]=Z;

	//normalize(test);

	vector<float> color(3,1);

	Plane MyPlane(color,points);
	vector<float> norm = MyPlane.getNormal();

	cout<< norm[0] << " ; " << norm[1] << " ; " << norm[2] << endl;

    return 0;
}
