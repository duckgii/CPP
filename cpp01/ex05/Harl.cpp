#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout<<"It's Debug Level!!"<<std::endl;
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
	void		(Harl::*FcPointer[4])(void);
	std::string	name[4];

	FcPointer[0] = &Harl::debug;
	FcPointer[1] = &Harl::info;
	FcPointer[2] = &Harl::warning;
	FcPointer[3] = &Harl::error;
	name[0] = "debug";
	name[1] = "info";
	name[2] = "warning";
	name[3] = "error";

	for (int i=0; i < 4; i++)
	{
		if (name[i] == level)
		{
			(this->*FcPointer[i])();
			return ;
		}
	}
	std::cout<<"input is invalid!!"<<std::endl;
}