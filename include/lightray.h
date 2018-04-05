#ifndef LIGHTRAY_H
#define LIGHTRAY_H

#include <vector>
#include <math.h>


class LightRay
{
	public:
		LightRay(std::vector<float> const& colorRGB, std::vector<float> const& position, std::vector<float> const& direction);
		virtual ~LightRay();

		/***** ACCESSORS *****/
		std::vector<float> getPosition();
		std::vector<float> getDirection();
		std::vector<float> getRGB();

		/***** METHODS *****/
		int update(std::vector<float> const& newColor, std::vector<float> const& newDirection);
		std::vector<float> newColor(std::vector<float> const& emissionColor);


	protected:
	private:
		int nbBumps;
		std::vector<float> RGB;
		std::vector<float> position;
		std::vector<float> direction;


};

#endif // LIGHTRAY_H
