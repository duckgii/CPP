#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> num;
	std::vector<int>::iterator ite;
	
	for (int i = 1; i < 11; i++)
	{
		num.push_back(i);
	}
	for (int i = 0; i < 15; i++)
	{
		ite = easyfind(num, i);
		if (ite == num.end())
			std::cout<<"not found"<<std::endl;
		else
			std::cout<<*ite<<std::endl;
	}
}