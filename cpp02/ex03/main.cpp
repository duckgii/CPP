#include "Point.hpp"

int main( void )
{
	std::cout<<"in : "<<bsp(Point(0,0), Point(0,5), Point(5,0), Point(1,1))<<std::endl;
	std::cout<<"out : "<<bsp(Point(0,0), Point(0,5), Point(5,0), Point(2,0))<<std::endl;
	std::cout<<"out : "<<bsp(Point(0,0), Point(0,5), Point(5,0), Point(-1,3))<<std::endl;
	std::cout<<"in : "<<bsp(Point(0,0), Point(0,10), Point(5,5), Point(3,5))<<std::endl;
	std::cout<<"out : "<<bsp(Point(0,0), Point(0,10), Point(5,5), Point(0,10))<<std::endl;
	std::cout<<"out : "<<bsp(Point(0,0), Point(0,10), Point(5,5), Point(10,1))<<std::endl;
	return (0);
}