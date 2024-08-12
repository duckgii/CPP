#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	man1("sungyoon");
	ClapTrap	man2("yeoshin");
	ClapTrap	man3(man1);
	man3 = man2;

	man1.attack("yeoshin");
	man2.takeDamage(0);
	man2.beRepaired(5);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	man2.takeDamage(0);
	man1.attack("yeoshin");
	return (0);
}