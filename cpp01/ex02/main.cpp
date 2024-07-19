#include <iostream>
#include <string>

int main()
{
	std::string	value = "HI THIS IS BRAIN.";
	std::string	*point = &value;
	std::string &ref = value;

	std::cout<<&value<<std::endl;
	std::cout<<&point<<std::endl;
	std::cout<<&ref<<std::endl;

	std::cout<<value<<std::endl;
	std::cout<<point<<std::endl;
	std::cout<<ref<<std::endl;

	return (0);
}