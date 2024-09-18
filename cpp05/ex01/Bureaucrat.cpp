#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("none")
{
	std::cout<<"Bureaucrat Default constructor is called"<<std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string const _name, int const _grade) : name(_name)
{
	try
	{
		grade = _grade;
		if (_grade > 150)
			throw _grade;
		else if (_grade < 1)
			throw _grade;
	}
	catch(const int	_grade)
	{
		if (_grade > 150)
			this->GradeTooLowException();
		else
			this->GradeTooHighException();
	}
	
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

void	Bureaucrat::GradeTooHighException()
{
	std::cout<<this->getName()<<"'s grade is Too High. Maximum Grade is 1"<<std::endl;
}

void	Bureaucrat::GradeTooLowException()
{
	std::cout<<this->getName()<<"'s grade is Too Low. Minimum Grade is 150"<<std::endl;
}

void	Bureaucrat::IncrementGrade()
{
	try
	{
		if (grade < 2)
			throw grade;
		else if (grade > 150)
			throw grade;
		grade--;
	}
	catch(const int grade)
	{
		if (grade > 150)
			this->GradeTooLowException();
		else
			this->GradeTooHighException();
	}
}
void	Bureaucrat::DecrementGrade()
{
	try
	{
		if (grade < 1)
			throw grade;
		else if (grade > 149)
			throw grade;
		grade++;
	}
	catch(const int grade)
	{
		if (grade > 149)
			this->GradeTooLowException();
		else
			this->GradeTooHighException();
	}
}

void	Bureaucrat::signForm(Form &form)
{
	bool flag;

	flag = form.beSigned(*this);
	if (flag == true)
		std::cout<<this->getName()<<" signed "<<form.getName()<<std::endl;
	else
		std::cout<<this->getName()<<" couldn’t sign  "<<form.getName()<<" because bureaucrat's grade is too low"<<std::endl;

}