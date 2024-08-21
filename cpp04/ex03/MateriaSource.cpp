#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout<<"MateriaSource default constructor is called"<<std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout<<"MateriaSource default destructor is called"<<std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = copy._inventory[i];
	}
	std::cout<<"MateriaSource Copy constructor is called"<<std::endl;
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
	std::cout<<"MateriaSource Copy assignment operator is called"<<std::endl;
	return (*this);
}

void learnMateria(AMateria* in)
{
	AMateria *temp;
	temp->set_type(in->getType());

}

AMateria* createMateria(std::string const & type)
{}
