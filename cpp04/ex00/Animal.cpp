#include "Animal.hpp"

Animal::Animal()
{
	std::cout<<"Animal Default construtror is called"<<std::endl;
}

Animal::Animal(std::string _type) : Animal()
{
	type = _type;
}

Animal::~Animal()
{
	std::cout<<"Animal Default destructor is called"<<std::endl;
}

Animal::Animal(Animal &copy)
{
	std::cout<<"Animal Copy constructor is called"<<std::endl;
	type = copy.type;
}

Animal& Animal::operator=(const Animal &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Animal Copy assignment operator is called"<<std::endl;
	this->type = in.type;
	return (*this);
}

void	makeSount()
{
	std::cout<<"Hi! I'm Animal"<<std::endl;
}