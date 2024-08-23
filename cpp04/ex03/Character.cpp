#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	//std::cout<<"Character default constructor is called"<<std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	//std::cout<<"Character default destructor is called"<<std::endl;
}

Character::Character(std::string name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	_name = name;
}

Character::Character(const Character &copy)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = copy._inventory[i]->clone();
	}
	//std::cout<<"Character Copy constructor is called"<<std::endl;
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
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (in._inventory[i] != NULL)
			this->_inventory[i] = in._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	this->_name = in._name;
	//std::cout<<"Character Copy assignment operator is called"<<std::endl;
	return (*this);
}

std::string const &Character::getName() const {return (_name);}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			return;
		}
		if (this->_inventory[i]->getType() == m->getType())
			return;
	}
	return ;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		delete _inventory[idx];
}


void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (this->_inventory[idx] != NULL)
			_inventory[idx]->use(target);
	}
}
