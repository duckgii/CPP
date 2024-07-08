#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	idx = 1;
}

void	PhoneBook::AddContact()
{
	contact[idx].InitContact();
	if (idx < 8)
		idx += 1;
	else
		idx = 1;
}

void	PhoneBook::DisplayContact()
{
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"|     index|first name| last name|  nickname|"<<std::endl;
	std::cout<<"---------------------------------------------"<<std::endl;
	for (int i = 1; i < idx; i++)
	{
		contact[i].DisplayContact(i);
		std::cout<<"---------------------------------------------"<<std::endl;
	}
}

void	PhoneBook::SearchIndex()
{
	std::string	input;
	int			s_idx;

	while (1)
	{
		std::cout << "Input index : ";
		std::cin >> input;
		s_idx = std::atoi(input.c_str());
		if (s_idx < idx && s_idx > 0)
			break;
		else
			std::cout << "Wrong index!!"<<std::endl;
	}
	contact[s_idx].DisplayAllInfo();
}