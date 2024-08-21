#include "Character.hpp"

Character::Character()
{
	std::cout<<"Character default constructor is called"<<std::endl;
}

Character::~Character()
{
	std::cout<<"Character default destructor is called"<<std::endl;
}

Character::Character(const Character &copy)
{
	std::cout<<"Character Copy constructor is called"<<std::endl;
}

Character&	Character::operator=(const Character &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Character Copy assignment operator is called"<<std::endl;
	return (*this);
}

void Character::use(int idx, ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}

AMateria *Character::clone() const
{
	Character*	ret = new Character();
	ret->_type = this->_type;
	return (ret);
}
