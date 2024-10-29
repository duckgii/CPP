#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	BitcoinExchange obj;

	if (ac > 2)
	{
		std::cout<<"Input argument is wrong!!"<<std::endl;
		return (0);
	}
	try
	{
		obj.getData("data.csv", 1);
		if (av[1] == NULL)
			obj.getData("", 2);
		else
			obj.getData(av[1], 2);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);	
}