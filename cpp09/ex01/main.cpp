#include "RPN.hpp"

int main(int ac, char *av[])
{
	RPN	obj;
	if (ac != 2)
	{
		std::cout<<"Input argument is wrong!!"<<std::endl;
		return (0);
	}
	obj.run(av[1]);
}