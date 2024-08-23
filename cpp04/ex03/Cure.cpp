#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
	//std::cout<<"Cure default constructor is called"<<std::endl;
}

Cure::~Cure()
{
	//std::cout<<"Cure default destructor is called"<<std::endl;
}

Cure::Cure(const Cure &copy)
{
	//std::cout<<"Cure Copy constructor is called"<<std::endl;
	_type = copy._type;
}

Cure::Cure(const std::string & type)
{
	_type = type;
}

Cure&	Cure::operator=(const Cure &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	//std::cout<<"Cure Copy assignment operator is called"<<std::endl;
	this->_type = in._type;
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}