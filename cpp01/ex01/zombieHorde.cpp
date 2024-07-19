#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *ret;
	std::stringstream num;

	ret = new Zombie[N];
	for (int i=0; i < N; i++)
	{
		num << i;
		ret[i] = Zombie(name + num.str());
		num.str("");
	}
	return (ret);
}