#include "Megaphone.hpp"

int main(int ac, char *av[])
{
	Megaphone	obj;

	if (ac == 1)
	{
		obj.Noise();
		return (0);
	}
	else
	{
		for (int idx = 1; av[idx] != NULL; idx++)
		{
			std::cout<<obj.UpperCase(av[idx])<<" ";
		}
		std::cout<<std::endl;
	}
	return (0);
}
