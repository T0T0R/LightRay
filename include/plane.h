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

		/***** METHODS *****/
		std::vector<float> calcNormal(std::vector<std::vector<float> > points);


	protected:
	private:
		std::vector<float> RGB (3);
		std::vector<float> normalToPlane(3);
		std::vector<float> refPoint(3);
};

#endif // PLANE_H
