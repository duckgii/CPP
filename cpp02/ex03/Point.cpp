#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float a, const float b)
{
	x = Fixed(a);
	y = Fixed(b);
}

Point::~Point()
{}

float	Point::getPointX(void)
{
	return (x.toFloat());
}

float	Point::getPointY(void)
{
	return (y.toFloat());
}

Point::Point(const Point &copy)
{
	*this = copy;
}

Point&	Point::operator=(const Point &in)
{
	if (this == &in)
		return (*this);
	x = in.x; //같은 종류의 클래스끼리는 프라이빗 변수에 접근가능
	y = in.y;
	return (*this);
}
