#ifndef PLANE_H
#define PLANE_H

#include <vector>
#include <math.h>


class Plane
{
	public:
		Plane(std::vector<float> const& color, std::vector<std::vector<float> > const& points);
		virtual ~Plane();

		/***** ACCESSORS *****/
		std::vector<float> getRGB();
		std::vector<float> getNormal();
		std::vector<std::vector<float> > getPoints();

		/***** METHODS *****/
		std::vector<float> calcNormal(std::vector<std::vector<float> > const& points);
		std::vector<float> normalize(std::vector<float> & vec);


	protected:
	private:
		std::vector<float> RGB;
		std::vector<float> normalVector;
		std::vector<float> refPoint;
		std::vector<std::vector<float> > refPoints;
};

#endif // PLANE_H
