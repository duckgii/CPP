#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too Low!!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too High!!";
}

Bureaucrat::Bureaucrat() : name("none")
{
	std::cout<<"Bureaucrat Default constructor is called"<<std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string const _name, int const _grade) : name(_name)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
	grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName())
{
	this->grade = copy.grade;
	std::cout<<"Bureaucrat copy constructor is called"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat default destructor is called"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &in)
{
	if (this == &in)
	{
		std::cout<<"input is invalid!"<<std::endl;
		return (*this);
	}
	this->grade = in.grade;
	std::cout<<"Bureaucrat copy assignment operator is called"<<std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &in) 
{
	out<<in.getName()<<", bureaucrat grade "<<in.getGrade()<<std::endl;
	return (out);
}


int Bureaucrat::getGrade() const {return (grade);}

std::string Bureaucrat::getName() const {return (name);}

void	Bureaucrat::IncrementGrade()
{
	if (grade < 2)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw  Bureaucrat::GradeTooLowException();
	grade -= 1;
}
void	Bureaucrat::DecrementGrade()
{
	if (grade < 1)
		throw  GradeTooHighException();
	else if (grade > 149)
		throw  GradeTooLowException();
	grade++;
}