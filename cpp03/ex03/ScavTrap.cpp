#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
	this->sethitPoint(100);
	this->setenergyPoint(50);
	this->setattackDamage(20);
	std::cout<<"ScavTrap Default constructor called"<<std::endl;
}

ScavTrap::ScavTrap(std::string initname) : ClapTrap(initname)
{
	this->sethitPoint(100);
	this->setenergyPoint(50);
	this->setattackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap Destructor called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout<<"ScavTrap Copy constructor called"<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"ScavTrap Copy assignment operator called"<<std::endl;
	setname(in.getName());
	sethitPoint(in.gethitPoint());
	setenergyPoint(in.getenergyPoint());
	setattackDamage(in.getattackDamage());
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout<<"ClapTrap "<<this->getName()<<" is now in Gate keeper mode."<<std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->gethitPoint() == 0)
	{
		std::cout<<this->getName()<<" has no hitpoint"<<std::endl;
		return ;
	}
	if (this->getenergyPoint() == 0)
	{
		std::cout<<this->getName()<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	energyPoint--;
	std::cout<<"ScavTrap "<<this->getName()<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!"<<std::endl;
}

