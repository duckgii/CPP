#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		Zombie(std::string input);
		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif