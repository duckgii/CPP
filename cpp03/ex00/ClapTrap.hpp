#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
	private:
		std::string	name;
		int	hitpoint;
		int	EnergyPoint;
		int	AttackDamage;
	public:
		ClapTrap(std::string initname);
		~ClapTrap();
		ClapTrap(ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap &in);

		int		getHitPoint() const;
		int		getEnergyPoint() const;
		int		getAttackDamage() const;
		std::string	getName() const ;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif