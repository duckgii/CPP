#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45)
{
	std::cout<<"RobotomyRequestForm default constructor is called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _name) : AForm(_name, false, 72, 45) {srand(time(0));}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy)
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getRequiredExecute())
		throw AForm::GradeTooLowException();
	std::cout<<"Drrrrrrrrrrrrrrrrrrrr!!\n";
	if (rand() % 2)
		std::cout<<this->getName()<<" has been robotomized successfully"<<std::endl;
	else
		std::cout<<this->getName()<<" robotomy failed."<<std::endl;
}