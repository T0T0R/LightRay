#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <vector>
#include <cmath>

#include "lightray.h"
#include "vector3.h"

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

class Plane
{
	public:
		Plane(std::vector<float> const& color, std::vector<std::vector<float> > const& points);
		Plane(std::vector<float> const& color, std::vector<Vector3 > const& points);
		virtual ~Plane();

		/***** ACCESSORS *****/
		std::vector<float> getRGB();
		Vector3 getNormal();
		Vector3 getPoint();
		std::vector<Vector3> getPoints();

		/***** METHODS *****/
		Vector3 calcNormal(std::vector<Vector3> & points);
		Vector3 intersect(LightRay ray);	//TO DO
		int reflect(LightRay & incidentRay);	//TO DO
		int debug();

	protected:
	private:
		std::vector<float> RGB;
		Vector3 normalVector;
		Vector3 refPoint;
		std::vector<Vector3> refPoints;
};

#endif // PLANE_H
