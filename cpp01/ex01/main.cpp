#include "Zombie.hpp"
#include <sstream>

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie	*crr;
	std::stringstream num;

	crr = zombieHorde(10, "Sungyoon");
	for (int i = 0; i < 10; i++)
	{
		crr[i].announce();
	}
	delete [] crr;
	return (0);
}