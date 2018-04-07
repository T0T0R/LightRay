#ifndef PLANE_H
#define PLANE_H

#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <iostream>
#include <vector>
#include <cmath>

#define ZERO 1E-7 //define near zero limit

#include "../include/lightray.h"
#include "../include/vector3.h"

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

class Plane
{
	public:
		Plane(std::vector<float> const& color, std::vector<std::vector<float> > const& points);
		Plane(std::vector<float> const& color, std::vector<Vector3 > const& points);
		Plane(std::vector<float> const& color, std::vector<float> const& equation);
		virtual ~Plane();

		/***** ACCESSORS *****/
		std::vector<float> getRGB() const;
		Vector3 getNormal() const;
		Vector3 getPoint() const;
		std::vector<Vector3> getPoints() const;

		/***** METHODS *****/
		Vector3 calcNormal(std::vector<Vector3> const& points);
		std::vector<float> getEquation() const;
		Vector3 intersect(LightRay const& ray) const;	//TO DO
		int reflect(LightRay & incidentRay) const;	//TO DO
		int debug() const;

	protected:
	private:
		std::vector<float> RGB;
		Vector3 normalVector;
		Vector3 refPoint;
		std::vector<Vector3> refPoints;
};

#endif // PLANE_H
