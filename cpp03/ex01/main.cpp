#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	man1("sungyoon");
	ScavTrap	man2("yeoshin");
	ScavTrap	man3(man1);
	man3 = man2;

	man1.attack("yeoshin");
	man2.takeDamage(20);
	man2.beRepaired(5);
	man1.attack("yeoshin");
	man2.takeDamage(20);
	man1.attack("yeoshin");
	man2.takeDamage(20);
	man1.attack("yeoshin");
	man2.takeDamage(20);
	man1.attack("yeoshin");
	man2.takeDamage(21);
	man1.attack("yeoshin");
	man2.takeDamage(22);
	man1.attack("yeoshin");
	man2.takeDamage(22);
	man1.guardGate();
}