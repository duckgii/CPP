#include "Point.hpp"

int main( void )
{
	std::cout<<bsp(Point(0,0), Point(0,5), Point(5,0), Point(1,1))<<std::endl;
	std::cout<<bsp(Point(0,0), Point(0,5), Point(5,0), Point(2,0))<<std::endl;
	return (0);
}