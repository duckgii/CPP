#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string input)
{
	type = input;
}

const std::string	Weapon::getType(void)
{
	const std::string	&str = type;
	return (str);
}

void	Weapon::setType(std::string input)
{
	type = input;
}
