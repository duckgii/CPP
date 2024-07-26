#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (checkTwoPoint(a, b, point) < 0 && checkTwoPoint(b, c, point) < 0 && checkTwoPoint(c, a, point) < 0)
		return (true);
	else if (checkTwoPoint(a, b, point) > 0 && checkTwoPoint(b, c, point) > 0 && checkTwoPoint(c, a, point) > 0)
		return (true);
	return (false);
}

double checkTwoPoint(Point p1, Point p2, Point point)
{
	Point	vec1(p1.getPointX() - point.getPointX(), p1.getPointY()- point.getPointY());
	Point	vec2(p2.getPointX() - point.getPointX(), p2.getPointY()- point.getPointY());;
	return (vec1.getPointX() * vec2.getPointY()- vec1.getPointY ()* vec2.getPointX());
}