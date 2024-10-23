#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
	PmergeMe obj;
	std::string input;
	std::string num;

	if (ac == 1)
	{
		std::cout<<"You have to input number!"<<std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		num = av[i];
		for (int j = 0; j < static_cast<int>(num.length()); j++)
		{
			if (isdigit(num[j]) == 0)
			{
				std::cout<<"Error"<<std::endl;
				return (0);
			}
		}
		input += av[i];
		input += " ";
	}
	obj.inputData(input);
	obj.runVector();
}