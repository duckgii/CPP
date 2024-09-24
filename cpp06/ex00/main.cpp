#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
	ScalarConverter temp;
	if (ac != 2)
	{
		std::cout<<"input is invalid!!"<<std::endl;
		return (0);
	}
	
	temp.convert(av[1]);
	return (0);
}