#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string initname)
{
	name = initname;
	hitpoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"Destructor called"<<std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;
	name = copy.getName();
	hitpoint = copy.getHitPoint();
	EnergyPoint = copy.getEnergyPoint();
	AttackDamage = copy.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Copy assignment operator called"<<std::endl;
	name = in.getName();
	hitpoint = in.getHitPoint();
	EnergyPoint = in.getEnergyPoint();
	AttackDamage = in.getAttackDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitpoint == 0)
	{
		std::cout<<name<<" has no hitpoint"<<std::endl;
		return ;
	}
	if (EnergyPoint == 0)
	{
		std::cout<<name<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	EnergyPoint--;
	std::cout<<"ClapTrap "<<name<<" attacks "<<target<<", causing "<<AttackDamage<<" points of damage!"<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitpoint == 0)
	{
		std::cout<<name<<" has no hitpoint"<<std::endl;
		return ;
	}
	if (EnergyPoint == 0)
	{
		std::cout<<name<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	if ((unsigned int)hitpoint < amount)
	{
		std::cout<<name<<" hitpoint is less then amount."<<std::endl;
		std::cout<<"ClapTrap "<<name<<" takes "<<hitpoint<<" points of damage."<<std::endl;
		hitpoint = 0;
	}
	else
		std::cout<<"ClapTrap "<<name<<" takes "<<amount<<" points of damage."<<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitpoint == 0)
	{
		std::cout<<name<<" has no hitpoint"<<std::endl;
		return ;
	}
	if (EnergyPoint == 0)
	{
		std::cout<<name<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	EnergyPoint--;
	std::cout<<"ClapTrap "<<name<<" repairs "<<amount<<" points of hit points."<<std::endl;
}

int	ClapTrap::getHitPoint() const { return hitpoint; }
int	ClapTrap::getEnergyPoint() const { return EnergyPoint; }
int	ClapTrap::getAttackDamage() const { return AttackDamage; }
std::string	ClapTrap::getName() const { return name; }