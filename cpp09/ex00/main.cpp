#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	BitcoinExchange obj;

	if (ac != 2)
	{
		std::cout<<"Input argument is wrong!!"<<std::endl;
		return (0);
	}
	try
	{
		obj.getData("data.csv", 1);
		obj.getData(av[1], 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);	
}