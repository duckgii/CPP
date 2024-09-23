#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout<<"Intern Default constructor is called"<<std::endl;
}

Intern::Intern(Intern &copy)
{
	(void)copy;
	std::cout<<"Intern copy constructor is called"<<std::endl;
}

Intern::~Intern()
{
	std::cout<<"Intern destructor is called"<<std::endl;
}

Intern&	Intern::operator=(Intern &in)
{
	if (this == &in)
	{
		std::cout<<"Input is wrong"<<std::endl;
		return (*this);
	}
	std::cout<<"Intern copy assignment operator is called"<<std::endl;
	return (*this);
}

AForm* Intern::make_robo(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::make_shru(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::make_presi(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm* (*fp[3])(std::string);
	std::string form_name[3];

	form_name[0] = "robotomy request";
	form_name[1] = "shrubbery creation";
	form_name[2] = "presidential pardon";
	fp[0] = make_robo;
	fp[1] = make_shru;
	fp[2] = make_presi;
	for (int i = 0; i < 3; i++)
	{
		if (form_name[i] == name)
			return (fp[i](target));
	}
	std::cout<<"Form name is invalid!!"<<std::endl;
	return (NULL);
}
