#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), name("")
{
	this->hitPoint = FragTrap::gethitPoint();
	this->energyPoint = ScavTrap::getenergyPoint();
	this->attackDamage = FragTrap::getattackDamage();
    std::cout<<"DiamondTrap Default constructor called"<<std::endl;
}

DiamondTrap::DiamondTrap(std::string initname) : ClapTrap(initname), name("")
{
    name = initname;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), name("")
{
    name = copy.name;
	std::cout<<"DiamondTrap Copy constructor called"<<std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout<<"DiamondTrap Default destructor called"<<std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &in)
{
	if (&in == this)
	{
		std::cout<<"invalid input"<<std::endl;
		return (*this);
	}
	std::cout<<"DiamondTrap Copy assignment operator called"<<std::endl;
	*this = in;
	this->name = in.name;
	return (*this);
}

// void	DiamondTrap::attack(const std::string& target) : ClapTrap::attack(target)
// {} //에러나는데 왜?

void	DiamondTrap::whoAmI()
{
	std::cout<<"Hello. My name is "<<this->name<<"and "<<ClapTrap::getName()<<std::endl;
}