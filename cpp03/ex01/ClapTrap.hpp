#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
	private:
		std::string	name;
		int	hitPoint;
		int	energyPoint;
		int	attackDamage;
	public:
		ClapTrap(std::string initname);
		~ClapTrap();
		ClapTrap(ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap &in);

		int		gethitPoint() const;
		int		getenergyPoint() const;
		int		getattackDamage() const;
		std::string	getName() const ;
		void	sethitPoint(int point);
		void	setenergyPoint(int point);
		void	setattackDamage(int point);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif