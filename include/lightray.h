#ifndef LIGHTRAY_H
#define LIGHTRAY_H

#include <vector>
#include <cmath>

#include "vector3.h"

/**
	std::vector<float>(3)	: used to store color and objects
	Vector3					: used to store 3 coordinates (position, direction...)
*/

class LightRay
{
	public:
		LightRay(std::vector<float> const& colorRGB, std::vector<float> const& position, std::vector<float> const& direction);
		LightRay(std::vector<float> const& colorRGB, Vector3 const& position, Vector3 const& direction);
		virtual ~LightRay();

		/***** ACCESSORS *****/
		Vector3 getPosition();
		Vector3 getDirection();
		std::vector<float> getRGB();

		/***** METHODS *****/
		int update(std::vector<float> const& newColor, Vector3 const& newDirection);	//TO DO
		std::vector<float> newColor(std::vector<float> const& incidentColor);
		int debug();

	protected:
	private:
		int nbBumps;
		std::vector<float> RGB;
		Vector3 position;
		Vector3 direction;
};

#endif // LIGHTRAY_H
