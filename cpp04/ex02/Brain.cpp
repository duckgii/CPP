#include "Brain.hpp"

Brain::Brain()
{
	ideas = new std::string[100];
	std::cout<<"Brain Default construtror is called"<<std::endl;
}

Brain::~Brain()
{
	delete []ideas;
	std::cout<<"Brain Default destructor is called"<<std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout<<"Brain Copy constructor is called"<<std::endl;
}

Brain& Brain::operator=(const Brain &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Brain Copy assignment operator is called"<<std::endl;
	*(this->ideas) = *(in.ideas);
	return (*this);
}