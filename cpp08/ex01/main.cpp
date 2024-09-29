#include <ctime>
#include <iostream>
#include "Span.hpp"

int main()
{
	srand(time(0));
	Span num(1000000);

	try
	{
		num.addManyNumber(1000000);
		std::cout<<num.shortestSpan()<<std::endl;
		std::cout<<num.longestSpan()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return(0);
}