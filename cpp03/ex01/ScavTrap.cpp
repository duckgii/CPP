#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string initname) : ClapTrap(initname)
{
	sethitPoint(100);
	setenergyPoint(50);
	setattackDamage(20);
	std::cout<<"ScavTrap Default constructor called"<<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap Destructor called"<<std::endl;
}

