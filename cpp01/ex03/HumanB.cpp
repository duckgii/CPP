#include "HumanB.hpp"

HumanB::HumanB(std::string input)
{
	name = input;
}
void	HumanB::setWeapon(Weapon &weapon)
{
	myWeapon = &weapon;
}
void	HumanB::attack(void)
{
	std::cout<<name<<" attacks with their "<<myWeapon->getType()<<std::endl;
}