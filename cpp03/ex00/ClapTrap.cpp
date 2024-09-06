#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string initname)
{
	name = initname;
	Hitpoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
	std::cout<<"ClapTrap Default constructor called"<<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap Destructor called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout<<"ClapTrap Copy constructor called"<<std::endl;
	name = copy.getName();
	Hitpoint = copy.getHitPoint();
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
	std::cout<<"ClapTrap Copy assignment operator called"<<std::endl;
	name = in.getName();
	Hitpoint = in.getHitPoint();
	EnergyPoint = in.getEnergyPoint();
	AttackDamage = in.getAttackDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (Hitpoint == 0)
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
	if (Hitpoint == 0)
	{
		std::cout<<name<<" has no hitpoint"<<std::endl;
		return ;
	}
	if (EnergyPoint == 0)
	{
		std::cout<<name<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	if ((unsigned int)Hitpoint < amount)
	{
		std::cout<<name<<" hitpoint is less then amount."<<std::endl;
		std::cout<<"ClapTrap "<<name<<" takes "<<Hitpoint<<" points of damage."<<std::endl;
		Hitpoint = 0;
	}
	else
	{
		std::cout<<"ClapTrap "<<name<<" takes "<<amount<<" points of damage."<<std::endl;
		Hitpoint -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (Hitpoint == 0)
	{
		std::cout<<name<<" has no Hitpoint"<<std::endl;
		return ;
	}
	if (EnergyPoint == 0)
	{
		std::cout<<name<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	EnergyPoint--;
	Hitpoint += amount;
	std::cout<<"ClapTrap "<<name<<" repairs "<<amount<<" points of hit points."<<std::endl;
	std::cout<<"So ClapTrap "<<name<<" has  "<<Hitpoint<<" points of hit points."<<std::endl;
}

int	ClapTrap::getHitPoint() const { return Hitpoint; }
int	ClapTrap::getEnergyPoint() const { return EnergyPoint; }
int	ClapTrap::getAttackDamage() const { return AttackDamage; }
std::string	ClapTrap::getName() const { return name; }