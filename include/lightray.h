#ifndef LIGHTRAY_H
#define LIGHTRAY_H

#include <vector>


class LightRay
{
	public:
		LightRay(float const& intensity, std::vector<float> const& colorRGB, std::vector<float> const& position, std::vector<float> const& direction);
		virtual ~LightRay();

		/***** ACCESSSORS *****/
		float getIntensity();
		std::vector<float> getPosition();
		std::vector<float> getDirection();
		std::vector<float> getRGB();

		/***** METHODS *****/
		std::vector<float> update(float const& newIntensity, std::vector<float> const& newDirection);

	protected:
	private:
		int nbBumps;
		float intensity;
		std::vector<float> RGB;
		std::vector<float> position;
		std::vector<float> direction;


};

#endif // LIGHTRAY_H
