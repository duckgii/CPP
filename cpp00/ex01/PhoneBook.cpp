#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	idx = 0;
	checkfirst = 1;
	booklen = 0;
}

void	PhoneBook::AddContact()
{
	contact[idx].InitContact();
	checkfirst = 0;
	idx += 1;
	booklen++;
	if (booklen > 8)
		booklen = 8;
	if (idx == 8)
		idx = 0;
}

void	PhoneBook::DisplayContact()
{
	if (checkfirst == 1)
		return;
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"|     index|first name| last name|  nickname|"<<std::endl;
	std::cout<<"---------------------------------------------"<<std::endl;
	for (int i = 0; i < booklen; i++)
	{
		contact[i].DisplayContact(i);
		std::cout<<"---------------------------------------------"<<std::endl;
	}
}

void	PhoneBook::SearchIndex()
{
	std::string	input;
	int			s_idx;

	if (checkfirst == 1)
	{
		std::cout<<"You should Add first!"<<std::endl;
		return ;
	}
	while (1)
	{
		std::cout << "Input index : ";
		std::getline(std::cin, input);
		PhoneBook::ClearCin();
		if (input == "")
		{
			std::cout<<std::endl;
			continue;
		}
		s_idx = std::atoi(input.c_str());
		if (s_idx <= booklen && s_idx > 0)
			break;
		else
			std::cout << "Wrong index!!"<<std::endl;
	}
	contact[s_idx - 1].DisplayAllInfo();
}

void	PhoneBook::ClearCin()
{
	if (std::cin.eof())
	{
		std::cin.clear();
		clearerr(stdin);
	}
}