#ifndef PLANE_H
#define PLANE_H

#include <vector>


class Plane
{
	public:
		Plane(std::vector<float> const& color, std::vector<std::vector<float> > const& points);
		Plane(std::vector<float> const& color, std::vector<float> const& normalPlane, std::vector<float> const& point);
		virtual ~Plane();

		/***** ACCESSORS *****/
		std::vector<float> getRGB();

	protected:
	private:
		std::vector<float> RGB;
		std::vector<float> normalToPlane;
		std::vector<float> refPoint;
};

#endif // PLANE_H
