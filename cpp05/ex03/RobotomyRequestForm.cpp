#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", false, 72, 45)
{
	std::cout<<"RobotomyRequestForm default constructor is called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _name) : Form(_name, false, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : Form(copy)
{
	std::cout<<"RobotomyRequestForm copy constructor is called"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm default destructor is called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &in)
{
	if (this == &in)
	{
		std::cout<<"input is invalid!"<<std::endl;
		return (*this);
	}
	std::cout<<"RobotomyRequestForm copy assignment operator is called"<<std::endl;
	return (*this);
}

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getRequiredExecute())
			throw executor.getGrade();
		std::cout<<"Drrrrrrrrrrrrrrrrrrrr!!";
		if (rand() % 2)
			std::cout<<this->getName()<<" has been robotomized successfully"<<std::endl;
		else
			std::cout<<this->getName()<<" robotomy failed."<<std::endl;
		return (true);
	}
	catch(const int grade)
	{
		this->GradeTooLowException("RequiredSign", grade);
		return (false);
	}
}