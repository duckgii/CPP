#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string initname);
		~ScavTrap();
		ScavTrap(ScavTrap &copy);
		ScavTrap& operator=(const ScavTrap &in);

		void	attack(const std::string& target);
		void	guardGate();
};

#endif