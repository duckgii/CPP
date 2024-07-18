#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string input);
		void	announce(void);
};

//Zombie* newZombie(std::string name);
//void	randomChump(std::string name);

#endif