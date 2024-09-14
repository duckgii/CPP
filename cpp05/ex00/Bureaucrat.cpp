#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout<<"Bureaucrat Default constructor is called"<<std::endl;
	this->name = "";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	try
	{
		if (_grade > 150)
			throw _grade;
		else if (_grade < 1)
			throw _grade;
		grade = _grade;
	}
	catch(const int	_grade)
	{
		if (_grade > 150)
			this->GradeTooLowException();
		else
			this->GradeTooHighException();
	}
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	this->name =  copy.name;
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
	this->name =  in.name;
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

void	Bureaucrat::GradeTooHighException()
{
	std::cout<<"Grade is Too High. Maximum Grade is 1"<<std::endl;
	grade = 1;
}

void	Bureaucrat::GradeTooLowException()
{
	std::cout<<"Grade is Too Low. Minimum Grade is 150"<<std::endl;
	grade = 150;
}
