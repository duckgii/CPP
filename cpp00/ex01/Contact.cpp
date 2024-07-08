#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

void	Contact::InitContact()
{
	std::cout<<"Input first name : ";
	std::cin>>first_name;
	std::cout<<"Input last name : ";
	std::cin>>last_name;
	std::cout<<"Input nickname : ";
	std::cin>>nick_name;
	std::cout<<"Input phone number : ";
	std::cin>>phone_number;
	std::cout<<"Input darkest secret : ";
	std::cin>>darkest_secret;

}

void	Contact::DisplayAllInfo()
{
	std::cout<<"first name is : "<<first_name<<std::endl;
	std::cout<<"last name is : "<<last_name<<std::endl;
	std::cout<<"nick name is : "<<nick_name<<std::endl;
	std::cout<<"phone number is : "<<phone_number<<std::endl;
	std::cout<<"darkest secret is : "<<darkest_secret<<std::endl;
}

void	Contact::DisplayContact(int i)
{
	std::string	str_temp;

	std::cout<<"|"<<std::setw(10)<<i;
	if (first_name.length() > 10)
	{
		str_temp = first_name.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout<<"|"<<std::setw(10)<<str_temp;
	if (last_name.length() > 10)
	{
		str_temp = last_name.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout<<"|"<<std::setw(10)<<str_temp;
	if (nick_name.length() > 10)
	{
		str_temp = nick_name.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout<<"|"<<std::setw(10)<<str_temp<<"|"<<std::endl;
}
