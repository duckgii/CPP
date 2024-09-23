#include "Bureaucrat.hpp" //include .cpp를 해서 duplicate symbol에러 발생했었음.
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat	shin1("yeoshin1", 10);
	Bureaucrat	shin2("yeoshin2", 1);
	PresidentialPardonForm	form1("linux");
	RobotomyRequestForm	form2("window");
	ShrubberyCreationForm	form3("centos");

	try
	{
	std::cout<<shin1;
	std::cout<<shin2;
	
	std::cout<<form1;
	std::cout<<form2;
	std::cout<<form3;
	std::cout<<std::endl<<std::endl;

	shin1.signForm(form1);
	shin1.signForm(form2);
	shin1.signForm(form3);
	std::cout<<std::endl;

	shin2.signForm(form1);
	shin2.signForm(form2);
	shin2.signForm(form3);
	std::cout<<std::endl<<std::endl;
	
	shin1.executeForm(form1);
	shin1.executeForm(form2);
	shin1.executeForm(form3);
	std::cout<<std::endl;

	shin1.IncrementGrade();
	shin1.executeForm(form1);
	std::cout<<std::endl<<std::endl;

	shin2.executeForm(form1);
	shin2.executeForm(form2);
	shin2.executeForm(form3);
	std::cout<<std::endl<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
