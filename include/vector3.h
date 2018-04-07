#ifndef VECTOR3_H
#define VECTOR3_H

#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

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
		Vector3(std::vector<float> const& vec);
		virtual ~Vector3();

		/***** ACCESSORS *****/
		float x() const;
		float y() const;
		float z() const;

		/***** MUTATORS *****/
		int x(float x);
		int y(float y);
		int z(float z);

		/***** METHODS *****/
		Vector3 normalize();
		std::vector<float> toVector() const;
		int debug() const;
		Vector3 product(Vector3 const& vec) const;
		Vector3 product(std::vector<float> const& vec) const;
		float scalar(Vector3 const& vec) const;
		float scalar(std::vector<float> const& vec) const;

	protected:
	private:
		float X, Y, Z;
};

#endif // VECTOR3_H
