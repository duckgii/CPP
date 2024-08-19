#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Brain Default construtror is called"<<std::endl;
}

Brain::~Brain()
{
	std::cout<<"Brain Default destructor is called"<<std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = copy.ideas[i];
	}
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
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = in.ideas[i];
	}
	return (*this);
}