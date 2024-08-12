#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	man1("sungyoon1");
	ClapTrap	man2("yeoshin1");
	ClapTrap	man3(man1);
	ScavTrap	man11("sungyoon2");
	ScavTrap	man12("yeoshin2");
	ScavTrap	man13(man11);
	FragTrap	man21("sungyoon3");
	FragTrap	man22("yeoshin3");
	FragTrap	man23(man21);

	man3 = man2;
	man13 = man12;
	man23 = man22;

	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man2.beRepaired(5);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");
	man2.takeDamage(0);
	man1.attack("yeoshin1");

	std::cout<<"\n\n\nScavTrap"<<std::endl;
	man11.attack("yeoshin2");
	man12.takeDamage(20);
	man12.beRepaired(5);
	man11.attack("yeoshin2");
	man12.takeDamage(20);
	man11.attack("yeoshin2");
	man12.takeDamage(20);
	man11.attack("yeoshin2");
	man12.takeDamage(20);
	man11.attack("yeoshin2");
	man12.takeDamage(20);
	man11.attack("yeoshin2");
	man12.takeDamage(20);
	man11.attack("yeoshin2");
	man12.takeDamage(20);
	man11.guardGate();


	std::cout<<"\n\n\nFragTrap"<<std::endl;

	man21.attack("yeoshin3");
	man22.takeDamage(30);
	man22.beRepaired(5);
	man21.attack("yeoshin3");
	man22.takeDamage(30);
	man21.attack("yeoshin3");
	man22.takeDamage(30);
	man21.attack("yeoshin3");
	man22.takeDamage(30);
	man21.attack("yeoshin3");
	man22.takeDamage(30);
	man21.attack("yeoshin3");
	man22.takeDamage(30);
	man21.attack("yeoshin3");
	man22.takeDamage(30);
	man21.highFivesGuys();
}