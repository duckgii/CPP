#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5)
{
	std::cout<<"PresidentialPardonForm default constructor is called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _name) : AForm(_name, false, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy)
{
	std::cout<<"PresidentialPardonForm copy constructor is called"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm default destructor is called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &in)
{
	if (this == &in)
	{
		std::cout<<"input is invalid!"<<std::endl;
		return (*this);
	}
	std::cout<<"PresidentialPardonForm copy assignment operator is called"<<std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getRequiredExecute())
		throw AForm::GradeTooLowException();
	std::cout<<this->getName()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}