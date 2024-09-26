#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::IsNotSigned::what() const throw()
{
	return "It is not signed!!";
}

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
	grade = _grade;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
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
		throw Bureaucrat::GradeTooLowException();
	grade--;
}
void	Bureaucrat::DecrementGrade()
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 149)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(AForm &Aform)
{
	try
	{
		Aform.beSigned(*this);
		std::cout<<this->getName()<<" signed "<<Aform.getName()<<std::endl;
	}
	catch(const std::exception& e)
	{
		if (Aform.getSigned())
			std::cout<<this->getName()<<" couldn’t signed "<<Aform.getName()<<" because Form is already signed"<<std::endl;
		else
			std::cout<<this->getName()<<" couldn’t signed "<<Aform.getName()<<" because Grade is not enough"<<std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (!form.getSigned())
		throw Bureaucrat::IsNotSigned();
	form.execute(*this);
	std::cout<<this->getName()<<" executed "<<form.getName()<<std::endl;
}