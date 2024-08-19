#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout<<"Cat Default construtror is called"<<std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat()
{
	delete brain;
	std::cout<<"Cat Default destructor is called"<<std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout<<"Cat Copy constructor is called"<<std::endl;
	brain = new Brain();
	type = copy.type;
	*brain = *(copy.brain);
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
	this->brain = in.brain;
	return (*this);
}

void	Cat::makeSound()
{
	std::cout<<"Meowwwwwwwwwwww"<<std::endl;
}