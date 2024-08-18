#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout<<"Cat Default construtror is called"<<std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout<<"Cat Default destructor is called"<<std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout<<"Cat Copy constructor is called"<<std::endl;
	type = copy.type;
}

Cat& Cat::operator=(const Cat &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Cat Copy assignment operator is called"<<std::endl;
	this->type = in.type;
	return (*this);
}

void	Cat::makeSound()
{
	std::cout<<"Meowwwwwwwwwwww"<<std::endl;
}