#include "Bureaucrat.hpp" //include .cpp를 해서 duplicate symbol에러 발생했었음.

int main()
{
	Bureaucrat	s;
	Bureaucrat	shin("yeoshin", 2);
	Bureaucrat	shin1("yeoshin1", 1);
	Bureaucrat	shin2("yeoshin2", 0);
	Bureaucrat	shin3("yeoshin3", 149);
	Bureaucrat	shin4("yeoshin4", 151);

	std::cout<<shin;
	std::cout<<shin1;
	std::cout<<shin2;
	std::cout<<shin3;
	std::cout<<shin4;
	shin2.IncrementGrade();
	std::cout<<shin2;
	shin3.DecrementGrade();
	std::cout<<shin3;
	shin3.DecrementGrade();
	shin.IncrementGrade();
	std::cout<<shin;
	shin.IncrementGrade();
	std::cout<<shin;
	return (0);
}
