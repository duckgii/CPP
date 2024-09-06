#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
	protected:
		std::string	name;
		int	hitPoint;
		int	energyPoint;
		int	attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string initname);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap &in);

		int		gethitPoint() const;
		int		getenergyPoint() const;
		int		getattackDamage() const;
		std::string	getName() const ;
		void	sethitPoint(int point);
		void	setenergyPoint(int point);
		void	setattackDamage(int point);
		void	setname(std::string input);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif