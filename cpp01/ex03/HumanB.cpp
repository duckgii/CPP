#include "HumanB.hpp"

HumanB::HumanB(std::string input)
{
	name = input;
	myweapon = NULL:
}
void	HumanB::setWeapon(Weapon &weapon)
{
	myWeapon = &weapon;
}
void	HumanB::attack(void)
{
	if (myweapon == NULL)
	{
		std::cout<<name<<" empty weapon"<<std::endl;
		return ;
	}
	std::cout<<name<<" attacks with their "<<myWeapon->getType()<<std::endl;
}