#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too Low!!";
}

AForm::AForm() : name(""), IsSigned(false), RequiredSign(1), RequiredExecute(1) // 이니셜라이저는 변수 초기화를 변수 선언 순서대로 진행해야한다.
{
	std::cout<<"AForm default constructor is called"<<std::endl;
}

AForm::AForm(std::string _name, bool issigned, int requirdsign, int requiredexecute) : name(_name), IsSigned(issigned), RequiredSign(requirdsign), RequiredExecute(requiredexecute) // 이니셜라이저는 변수 초기화를 변수 선언 순서대로 진행해야한다.
{
	if (requirdsign > 150)
		throw AForm::GradeTooLowException();
	else if (requirdsign < 1)
		throw AForm::GradeTooHighException();
	if (requiredexecute > 150)
		throw AForm::GradeTooLowException();
	else if (requiredexecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm &copy) : name(copy.getName()), IsSigned(copy.getSigned()), RequiredSign(copy.getRequiredSign()), RequiredExecute(copy.getRequiredExecute())
{
	std::cout<<"AForm copy constructor is called"<<std::endl;
}

AForm::~AForm()
{
	std::cout<<"AForm default descructor is called"<<std::endl;
}

AForm& AForm::operator=(AForm &in)
{
	if (this == &in)
	{
		std::cout<<"input is invalid!!"<<std::endl;
		return (*this);
	}
	IsSigned = in.getSigned();
	std::cout<<"AForm copy assignment operator is called"<<std::endl;
	return (*this);
}

bool	AForm::getSigned() const {return (IsSigned);};
std::string AForm::getName() const {return (name);};
int		AForm::getRequiredSign() const {return (RequiredSign);};
int		AForm::getRequiredExecute() const {return (RequiredExecute);};

std::ostream& operator<<(std::ostream &out, const AForm &in) 
{
	std::string sign;
	sign = (in.getSigned() == true) ? "true" : "false";
	out<<in.getName()<<", AForm signed "<<sign<<", grade required sign "<<in.getRequiredSign()<<", grade requird execute "<<in.getRequiredExecute()<<std::endl;
	return (out);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredSign() || this->IsSigned == true)
		throw AForm::GradeTooLowException();
	this->IsSigned = true;
}
