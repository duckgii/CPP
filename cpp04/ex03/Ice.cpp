#include "Ice.hpp"

Ice::Ice()
{
	_type = "none";
	std::cout<<"Ice default constructor is called"<<std::endl;
}

Ice::~Ice()
{
	std::cout<<"Ice default destructor is called"<<std::endl;
}

Ice::Ice(const Ice &copy)
{
	std::cout<<"Ice Copy constructor is called"<<std::endl;
	_type = copy._type;
}

Ice::Ice(const std::string & type) : Ice()
{
	_type = type;
}

Ice&	Ice::operator=(const Ice &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Ice Copy assignment operator is called"<<std::endl;
	this->_type = in._type;
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<std::endl;
}

AMateria *Ice::clone() const
{
	Ice*	ret = new Ice();
	ret->_type = this->_type;
	return (ret);
}