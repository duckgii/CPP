#include "Bureaucrat.hpp" //include .cpp를 해서 duplicate symbol에러 발생했었음.
#include "Form.hpp"

int main()
{
	try
	{	
	Bureaucrat	shin1("yeoshin1", 10);
	Bureaucrat	shin2("yeoshin2", 30);
	Form	form1("linux", false, 9, 9);
	Form	form2("window", false, 15, 15);
	Form	form3("mac", false, 40, 40);
	//Form	form4("centos", false, 0, 151);

	std::cout<<shin1;
	std::cout<<shin2;
	
	std::cout<<form1;
	std::cout<<form2;
	std::cout<<form3;
	std::cout<<std::endl<<std::endl;

	//shin1.signForm(form1);
	shin1.signForm(form2);
	shin1.signForm(form3);
	std::cout<<std::endl;

	//shin1.IncrementGrade();
	shin1.signForm(form1);
	std::cout<<std::endl<<std::endl;

	shin2.signForm(form1);
	shin2.signForm(form2);
	shin2.signForm(form3);
	std::cout<<std::endl<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
