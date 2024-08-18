#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout<<"WrongCat Default construtror is called"<<std::endl;
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat Default destructor is called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout<<"WrongCat Copy constructor is called"<<std::endl;
	type = copy.type;
}

WrongCat& WrongCat::operator=(const WrongCat &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"WrongCat Copy assignment operator is called"<<std::endl;
	this->type = in.type;
	return (*this);
}