#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	idx = 0;
}

void	PhoneBook::AddContact()
{
	contact[idx].InitContact();
	if (idx < 7)
		idx += 1;
	else
		idx = 0;
}

void	PhoneBook::DisplayContact()
{
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"|     index|first name| last name|  nickname|"<<std::endl;
	std::cout<<"---------------------------------------------"<<std::endl;
	for (int i = 0; i < idx; i++)
	{
		contact[i].DisplayContact(i);
		std::cout<<"---------------------------------------------"<<std::endl;
	}
}

void	PhoneBook::SearchIndex()
{
	int		s_idx;

	while (1)
	{
		std::cout << "Input index : ";
		std::cin >> s_idx;
		if (s_idx < idx && s_idx >= 0)
			break;
		else
			std::cout << "Wrong index!!";
	}
	contact[s_idx].DisplayAllInfo();
}