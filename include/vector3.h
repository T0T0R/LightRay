#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>
#include <vector>

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

class Vector3
{
	public:
		Vector3();
		Vector3(float x, float y, float z);
		Vector3(int x, int y, int z);
		Vector3(std::vector<float> vec);
		virtual ~Vector3();

		/***** ACCESSORS *****/
		float x();
		float y();
		float z();

		/***** MUTATORS *****/
		int x(float x);
		int y(float y);
		int z(float z);

		/***** METHODS *****/
		Vector3 normalize();
		std::vector<float> toVector();
		int debug();

	protected:
	private:
		float X, Y, Z;
};

#endif // VECTOR3_H
