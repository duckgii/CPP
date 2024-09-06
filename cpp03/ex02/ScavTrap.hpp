#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string initname);
		~ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap& operator=(const ScavTrap &in);

		void	guardGate();
		void	attack(const std::string& target);
};

#endif