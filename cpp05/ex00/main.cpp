#include "Bureaucrat.hpp" //include .cpp를 해서 duplicate symbol에러 발생했었음.

int main()
{
	try
	{		
		Bureaucrat	s;
		Bureaucrat	shin("yeoshin", 2);
		Bureaucrat	shin1("yeoshin1", 1);
		//Bureaucrat	shin2("yeoshin2", 0);
		Bureaucrat	shin3("yeoshin3", 149);
		//Bureaucrat	shin4("yeoshin4", 151);

		std::cout<<shin;
		std::cout<<shin1;
		shin1.IncrementGrade();
		std::cout<<shin3;
		shin3.DecrementGrade();
		std::cout<<shin3;
		shin3.DecrementGrade();
		shin.IncrementGrade();
		std::cout<<shin;
		shin.IncrementGrade();
		std::cout<<shin;
	}
	catch (std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
