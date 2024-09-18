#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name(""), IsSigned(false), RequiredSign(1), RequiredExecute(1) // 이니셜라이저는 변수 초기화를 변수 선언 순서대로 진행해야한다.
{
	std::cout<<"AForm default constructor is called"<<std::endl;
}

AForm::AForm(std::string _name, bool issigned, int requirdsign, int requiredexecute) : name(_name), IsSigned(issigned), RequiredSign(requirdsign), RequiredExecute(requiredexecute) // 이니셜라이저는 변수 초기화를 변수 선언 순서대로 진행해야한다.
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
void	AForm::setSigned() {IsSigned = true;};
std::string AForm::getName() const {return (name);};
int		AForm::getRequiredSign() const {return (RequiredSign);};
int		AForm::getRequiredExecute() const {return (RequiredExecute);};

void AForm::GradeTooHighException(std::string option, int value) const
{
	std::cout<<this->getName()<<"'s "<<option<<" is Too High. its Grade is "<<value<<std::endl;
}

void AForm::GradeTooLowException(std::string option, int value) const
{
	std::cout<<this->getName()<<"'s "<<option<<" is Too Low. its Grade is "<<value<<std::endl;
}

std::ostream& operator<<(std::ostream &out, const AForm &in) 
{
	std::string sign;
	sign = (in.getSigned() == true) ? "true" : "false";
	out<<in.getName()<<", AForm signed "<<sign<<", grade required sign "<<in.getRequiredSign()<<", grade requird execute "<<in.getRequiredExecute()<<std::endl;
	return (out);
}

bool	AForm::beSigned(Bureaucrat &bureaucrat)
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
