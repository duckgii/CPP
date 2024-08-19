#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout<<"AAnimal Default construtror is called"<<std::endl;
	type = "none";
}

AAnimal::~AAnimal()
{
	std::cout<<"AAnimal Default destructor is called"<<std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout<<"AAnimal Copy constructor is called"<<std::endl;
	type = copy.type;
}

AAnimal& AAnimal::operator=(const AAnimal &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"AAnimal Copy assignment operator is called"<<std::endl;
	this->type = in.type;
	return (*this);
}

std::string	AAnimal::getType() {return (type);}