#include "Zombie.hpp"
#include <sstream>

int main()
{
	Zombie	*crr;
	std::stringstream num;

	for (int i = 0; i < 10; i++)
	{
		num << i;
		crr = newZombie("Sungyoon" + num.str());
		crr->announce();
		delete(crr);
		num.str("");
	}
	for (int i = 0; i < 10; i++)
	{
		num << i;
		randomChump("Sungyoon_ver" + num.str());
		num.str("");
	}
	return (0);
}