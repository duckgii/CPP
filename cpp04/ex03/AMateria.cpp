#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "none";
	//std::cout<<"AMateria default constructor is called"<<std::endl;
}

AMateria::~AMateria()
{
	//std::cout<<"AMateria default destructor is called"<<std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	//std::cout<<"AMateria Copy constructor is called"<<std::endl;
	_type = copy._type;
}

AMateria::AMateria(const std::string & type)
{
	_type = type;
}

AMateria& AMateria::operator=(const AMateria &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	//std::cout<<"AMateria Copy assignment operator is called"<<std::endl;
	this->_type = in._type;
	return (*this);
}

std::string const & AMateria::getType() const {return (_type);}

void	AMateria::setType(const std::string input) {_type = input;} //Returns the materia type

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout<<"AMateria use"<<std::endl;
}
