#include "vector3.h"

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

using namespace std;

Vector3::Vector3():
	X(0.0),Y(0.0),Z(0.0)
{}


Vector3::Vector3(float x, float y, float z):
	X(x), Y(y), Z(z)
{}

Vector3::Vector3(int x, int y, int z)
{
	X = (float) x;
	Y = (float) y;
	Z = (float) z;
}

Vector3::Vector3(vector<float> vec):
	X(vec[0]), Y(vec[1]), Z(vec[2])
{}

Vector3::~Vector3()
{
	//dtor
}



/***** ACCESSORS *****/
float Vector3::x(){return X;}
float Vector3::y(){return Y;}
float Vector3::z(){return Z;}



/***** MUTATORS *****/
int Vector3::x(float x){X=x; return 0;}
int Vector3::y(float y){Y=y; return 0;}
int Vector3::z(float z){Z=z; return 0;}



/***** METHODS *****/
Vector3 Vector3::normalize(){
	float x = X/sqrt(pow(X,2)+pow(Y,2)+pow(Z,2));
	float y = Y/sqrt(pow(X,2)+pow(Y,2)+pow(Z,2));
	float z = Z/sqrt(pow(X,2)+pow(Y,2)+pow(Z,2));
	X=x;
	Y=y;
	Z=z;
	return *this;
}


vector<float> Vector3::toVector(){
	vector<float> myVec(3);
	myVec[0] = X;
	myVec[1] = Y;
	myVec[2] = Z;
	return myVec;
}


int Vector3::debug(){
	cout<<"[DEBUG - VECTOR3] - "<<X<<";"<<Y<<";"<<Z<<endl;
	return 0;
}
