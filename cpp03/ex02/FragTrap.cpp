#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {}

FragTrap::FragTrap(std::string initname) : ClapTrap(initname)
{
	this->sethitPoint(100);
	this->setenergyPoint(100);
	this->setattackDamage(30);
	std::cout<<"FragTrap Default constructor called"<<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap Destructor called"<<std::endl;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	std::cout<<"FragTrap Copy constructor called"<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"FragTrap Copy assignment operator called"<<std::endl;
	setname(in.getName());
	sethitPoint(in.gethitPoint());
	setenergyPoint(in.getenergyPoint());
	setattackDamage(in.getattackDamage());
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout<<"FragTrap "<<this->getName()<<" high fives"<<std::endl;
}
