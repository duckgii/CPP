#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::Zombie(std::string input)
{
	name = input;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout<<name<<": Destructor is called"<<std::endl;
}
