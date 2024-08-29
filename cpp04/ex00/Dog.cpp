#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout<<"Dog Default construtror is called"<<std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout<<"Dog Default destructor is called"<<std::endl;
}

Dog::Dog(const Dog &copy) : Dog(copy)
{
	std::cout<<"Dog Copy constructor is called"<<std::endl;
}

Dog& Dog::operator=(const Dog &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Dog Copy assignment operator is called"<<std::endl;
	this->type = in.type;
	return (*this);
}

void	Dog::makeSound()
{
	std::cout<<"Woofffffffffffffff"<<std::endl;
}