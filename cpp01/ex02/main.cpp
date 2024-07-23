#include <iostream>
#include <string>

int main()
{
	std::string	value = "HI THIS IS BRAIN.";
	std::string	*stringPTR = &value;
	std::string &stringREF = value;

	std::cout<<&value<<std::endl;
	std::cout<<&stringPTR<<std::endl;
	std::cout<<&stringREF<<std::endl;

	std::cout<<value<<std::endl;
	std::cout<<stringPTR<<std::endl;
	std::cout<<stringREF<<std::endl;

	return (0);
}