#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout<<"WrongAnimal Default construtror is called"<<std::endl;
	type = "wrong";
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal Default destructor is called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout<<"WrongAnimal Copy constructor is called"<<std::endl;
	type = copy.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"WrongAnimal Copy assignment operator is called"<<std::endl;
	this->type = in.type;
	return (*this);
}

void	WrongAnimal::makeSound()
{
	std::cout<<"Wrongggggggggg"<<std::endl;
}

std::string	WrongAnimal::getType() {return (type);}