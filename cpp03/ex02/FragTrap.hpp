#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string initname);
		~FragTrap();
		FragTrap(FragTrap &copy);
		FragTrap& operator=(const FragTrap &in);

		void highFivesGuys(void);
};

#endif