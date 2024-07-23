#include "Harl.hpp"

void	Harl::DEBUG(void)
{
	std::cout<<"It's DEBUG Level!!"<<std::endl;
}

void	Harl::INFO(void)
{
	std::cout<<"It's INFO Level!!"<<std::endl;
}

void	Harl::WARNING(void)
{
	std::cout<<"It's WARNING Level!!"<<std::endl;
}

void	Harl::ERROR(void)
{
	std::cout<<"It's ERROR Level!!"<<std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*FcPointer[4])(void);
	std::string	name[4];

	FcPointer[0] = &Harl::DEBUG;
	FcPointer[1] = &Harl::INFO;
	FcPointer[2] = &Harl::WARNING;
	FcPointer[3] = &Harl::ERROR;
	name[0] = "DEBUG";
	name[1] = "INFO";
	name[2] = "WARNING";
	name[3] = "ERROR";

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