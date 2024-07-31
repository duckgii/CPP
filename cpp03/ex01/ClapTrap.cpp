#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string initname)
{
	name = initname;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
	std::cout<<"ClapTrap Default constructor called"<<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap Destructor called"<<std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout<<"ClapTrap Copy constructor called"<<std::endl;
	name = copy.getName();
	hitPoint = copy.gethitPoint();
	energyPoint = copy.getenergyPoint();
	attackDamage = copy.getattackDamage();
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
	hitPoint = in.gethitPoint();
	energyPoint = in.getenergyPoint();
	attackDamage = in.getattackDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoint == 0)
	{
		std::cout<<name<<" has no hitpoint"<<std::endl;
		return ;
	}
	if (energyPoint == 0)
	{
		std::cout<<name<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	energyPoint--;
	std::cout<<"ClapTrap "<<name<<" attacks "<<target<<", causing "<<attackDamage<<" points of damage!"<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint == 0)
	{
		std::cout<<name<<" has no hitpoint"<<std::endl;
		return ;
	}
	if (energyPoint == 0)
	{
		std::cout<<name<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	if ((unsigned int)hitPoint < amount)
	{
		std::cout<<name<<" hitpoint is less then amount."<<std::endl;
		std::cout<<"ClapTrap "<<name<<" takes "<<hitPoint<<" points of damage."<<std::endl;
		hitPoint = 0;
	}
	else
		std::cout<<"ClapTrap "<<name<<" takes "<<amount<<" points of damage."<<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoint == 0)
	{
		std::cout<<name<<" has no hitpoint"<<std::endl;
		return ;
	}
	if (energyPoint == 0)
	{
		std::cout<<name<<" has no EnergyPoint"<<std::endl;
		return ;
	}
	energyPoint--;
	std::cout<<"ClapTrap "<<name<<" repairs "<<amount<<" points of hit points."<<std::endl;
}

int	ClapTrap::gethitPoint() const { return hitPoint; }
int	ClapTrap::getenergyPoint() const { return energyPoint; }
int	ClapTrap::getattackDamage() const { return attackDamage; }
std::string	ClapTrap::getName() const { return name; }

void	ClapTrap::sethitPoint(int point) { hitPoint = point; }
void	ClapTrap::setenergyPoint(int point) { hitPoint = point; }
void	ClapTrap::setattackDamage(int point) { hitPoint = point; }