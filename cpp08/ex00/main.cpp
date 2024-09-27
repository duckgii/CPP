#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> num;

	for (int i = 1; i < 11; i++)
	{
		num.push_back(i);
	}
	std::cout<<easyfind(num, 1)<<std::endl;
	std::cout<<easyfind(num, 2)<<std::endl;
	std::cout<<easyfind(num, 3)<<std::endl;
	std::cout<<easyfind(num, 4)<<std::endl;
	std::cout<<easyfind(num, 5)<<std::endl;
	std::cout<<easyfind(num, 11)<<std::endl;
}