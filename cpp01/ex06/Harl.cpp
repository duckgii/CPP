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
	std::string	name[4];

	name[0] = "DEBUG";
	name[1] = "INFO";
	name[2] = "WARNING";
	name[3] = "ERROR";
	for (int i=0; i < 4; i++)
	{
		if (name[i] == level)
		{
			switch (i)
			{
			case 0 :
				Harl::DEBUG();
				//FALLTHROUGH
			case 1 :
				Harl::INFO();
				//FALLTHROUGH
			case 2 :
				Harl::WARNING();
				//FALLTHROUGH
			case 3 :
				Harl::ERROR();
				break;
			}
			return ;
		}
	}
	std::cout<<"input is invalid!!"<<std::endl;
}