#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	//std::cout<<"MateriaSource default constructor is called"<<std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	//std::cout<<"MateriaSource default destructor is called"<<std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = copy._inventory[i];
	}
	//std::cout<<"MateriaSource Copy constructor is called"<<std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &in)
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
	//std::cout<<"MateriaSource Copy assignment operator is called"<<std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* in)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = in;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			if (_inventory[i]->getType() == type)
				return (_inventory[i]->clone());
		}
	}
	return (0);
}
