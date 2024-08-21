#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout<<"Character default constructor is called"<<std::endl;
}

Character::~Character()
{
	std::cout<<"Character default destructor is called"<<std::endl;
}

Character::Character(std::string name) : _name(name) {}

Character::Character(const Character &copy)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = copy._inventory[i];
	}
	std::cout<<"Character Copy constructor is called"<<std::endl;
}

Character&	Character::operator=(const Character &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = in._inventory[i];
	}
	std::cout<<"Character Copy assignment operator is called"<<std::endl;
	return (*this);
}

std::string const &Character::getName() const {return (_name);}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == m)
			return;
		else if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] == m;
			return;
		}
	}
	return ;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
	(this->_inventory[idx])->use(target);	
}
