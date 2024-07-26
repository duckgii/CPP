#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		Point(const float a, const float b);
		Point(const Point &copy);
		~Point();
		float	getPointX();
		float	getPointY();

		Point&	operator=(const Point &in);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
double checkTwoPoint(Point p1, Point p2, Point point);

#endif
