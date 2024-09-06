#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
		int			hitPoint;
		int			energyPoint;
		int			attackDamage;
	
	public:
		DiamondTrap();
		DiamondTrap(std::string initname);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap &in);
		void	whoAmI();
		// void	attack(const std::string& target);


};

#endif