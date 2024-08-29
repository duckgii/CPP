#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout<<"Dog Default construtror is called"<<std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog()
{
	delete brain;
	std::cout<<"Dog Default destructor is called"<<std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	std::cout<<"Dog Copy constructor is called"<<std::endl;
	brain = new Brain();
	*brain = *(copy.brain);
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
	this->brain = in.brain;
	return (*this);
}

void	Dog::makeSound()
{
	std::cout<<"Woofffffffffffffff"<<std::endl;
}