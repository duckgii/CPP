#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name(""), IsSigned(false), RequiredSign(1), RequiredExecute(1) // 이니셜라이저는 변수 초기화를 변수 선언 순서대로 진행해야한다.
{
	std::cout<<"Form default constructor is called"<<std::endl;
}

Form::Form(std::string _name, bool issigned, int requirdsign, int requiredexecute) : name(_name), IsSigned(issigned), RequiredSign(requirdsign), RequiredExecute(requiredexecute) // 이니셜라이저는 변수 초기화를 변수 선언 순서대로 진행해야한다.
{
	try
	{
		if (requirdsign > 150)
			throw requirdsign;
		else if (requirdsign < 1)
			throw requirdsign;
	}
	catch(const int	requirdsign)
	{
		if (requirdsign > 150)
			this->GradeTooLowException("RequiredSign", requirdsign);
		else
			this->GradeTooHighException("RequiredSign", requirdsign);
	}
	try
	{
		if (requiredexecute > 150)
			throw requiredexecute;
		else if (requiredexecute < 1)
			throw requiredexecute;
	}
	catch(const int	requiredexecute)
	{
		if (requiredexecute > 150)
			this->GradeTooLowException("RequiredExecute", requiredexecute);
		else
			this->GradeTooHighException("RequiredExecute", requiredexecute);
	}
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
void	Form::setSigned() {IsSigned = true;};
std::string Form::getName() const {return (name);};
int		Form::getRequiredSign() const {return (RequiredSign);};
int		Form::getRequiredExecute() const {return (RequiredExecute);};

void Form::GradeTooHighException(std::string option, int value) const
{
	std::cout<<this->getName()<<"'s "<<option<<" is Too High. its Grade is "<<value<<std::endl;
}

void Form::GradeTooLowException(std::string option, int value) const
{
	std::cout<<this->getName()<<"'s "<<option<<" is Too Low. its Grade is "<<value<<std::endl;
}

std::ostream& operator<<(std::ostream &out, const Form &in) 
{
	std::string sign;
	sign = (in.getSigned() == true) ? "true" : "false";
	out<<in.getName()<<", Form signed "<<sign<<", grade required sign "<<in.getRequiredSign()<<", grade requird execute "<<in.getRequiredExecute()<<std::endl;
	return (out);
}

bool	Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->getRequiredSign())
			throw bureaucrat.getGrade();
		this->setSigned();
		return (true);
	}
	catch(const int	Grade)
	{
		this->GradeTooLowException("RequiredSign", Grade);
		return (false);
	}
}
