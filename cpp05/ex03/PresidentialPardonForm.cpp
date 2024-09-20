#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", false, 25, 5)
{
	std::cout<<"PresidentialPardonForm default constructor is called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _name) : Form(_name, false, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : Form(copy)
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

bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getRequiredExecute())
			throw executor.getGrade();
		std::cout<<this->getName()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
		return (true);
	}
	catch(const int grade)
	{
		this->GradeTooLowException("RequiredSign", grade);
		return (false);
	}
}