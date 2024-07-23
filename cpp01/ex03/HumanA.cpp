#include "HumanA.hpp"

HumanA::HumanA(std::string input, Weapon &weapon) : name(input), myWeapon(weapon) {}

void	HumanA::attack(void)
{
	std::cout<<name<<" attacks with their "<<myWeapon.getType()<<std::endl;
}