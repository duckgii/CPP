#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too Low!!";
}

Form::Form() : name(""), IsSigned(false), RequiredSign(1), RequiredExecute(1) // 이니셜라이저는 변수 초기화를 변수 선언 순서대로 진행해야한다.
{
	std::cout<<"Form default constructor is called"<<std::endl;
}

Form::Form(std::string _name, bool issigned, int requirdsign, int requiredexecute) : name(_name), IsSigned(issigned), RequiredSign(requirdsign), RequiredExecute(requiredexecute) // 이니셜라이저는 변수 초기화를 변수 선언 순서대로 진행해야한다.
{
	if (requirdsign > 150)
		throw Form::GradeTooLowException();
	else if (requirdsign < 1)
		throw Form::GradeTooHighException();
	if (requiredexecute > 150)
		throw Form::GradeTooLowException();
	else if (requiredexecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form &copy) : name(copy.getName()), IsSigned(copy.getSigned()), RequiredSign(copy.getRequiredSign()), RequiredExecute(copy.getRequiredExecute())
{
	std::cout<<"Form copy constructor is called"<<std::endl;
}

Form::~Form()
{
	std::cout<<"Form default descructor is called"<<std::endl;
}

Form& Form::operator=(Form &in)
{
	if (this == &in)
	{
		std::cout<<"input is invalid!!"<<std::endl;
		return (*this);
	}
	IsSigned = in.getSigned();
	std::cout<<"Form copy assignment operator is called"<<std::endl;
	return (*this);
}

bool	Form::getSigned() const {return (IsSigned);};
std::string Form::getName() const {return (name);};
int		Form::getRequiredSign() const {return (RequiredSign);};
int		Form::getRequiredExecute() const {return (RequiredExecute);};

std::ostream& operator<<(std::ostream &out, const Form &in) 
{
	std::string sign;
	sign = (in.getSigned() == true) ? "true" : "false";
	out<<in.getName()<<", Form signed "<<sign<<", grade required sign "<<in.getRequiredSign()<<", grade requird execute "<<in.getRequiredExecute()<<std::endl;
	return (out);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredSign())
		throw Form::GradeTooLowException();
	this->IsSigned = true;
}
