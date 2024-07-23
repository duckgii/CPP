#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout<<"It's debug Level!!"<<std::endl;
}

void	Harl::info(void)
{
	std::cout<<"It's info Level!!"<<std::endl;
}

void	Harl::warning(void)
{
	std::cout<<"It's warning Level!!"<<std::endl;
}

void	Harl::error(void)
{
	std::cout<<"It's error Level!!"<<std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	name[4];

	name[0] = "debug";
	name[1] = "info";
	name[2] = "warning";
	name[3] = "error";
	for (int i=0; i < 4; i++)
	{
		if (name[i] == level)
		{
			switch (i)
			{
			case 0 :
				Harl::debug();
			case 1 :
				Harl::info();
			case 2 :
				Harl::warning();
			case 3 :
				Harl::error();
				break;
			}
			return ;
		}
	}
	std::cout<<"input is invalid!!"<<std::endl;
}