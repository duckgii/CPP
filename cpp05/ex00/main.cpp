#include "Bureaucrat.hpp" //include .cpp를 해서 duplicate symbol에러 발생했었음.

int main()
{
	Bureaucrat	shin("yeoshin", 5);
	//Bureaucrat	shin1("yeoshin", 1);
	Bureaucrat	shin2("yeoshin", 0);
	//Bureaucrat	shin3("yeoshin", 150);
	Bureaucrat	shin4("yeoshin", 151);

	std::cout<<shin;
	return (0);
}
