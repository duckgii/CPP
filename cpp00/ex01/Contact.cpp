#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

void	Contact::InitContact()
{
	first_name = GetString("Input first name : ");
	last_name = GetString("Input last name : ");
	nick_name = GetString("Input nickname : ");
	phone_number = GetString("Input phone number : ");
	while (Contact::IsNum(phone_number) == 0)
	{
		std::cout<<"Phone Number should consist of Number"<<std::endl;
		phone_number = GetString("Input phone number : ");
	}
	darkest_secret = GetString("Input darkest secret : ");
}

std::string Contact::GetString(std::string str)
{
	std::string	ret;

	std::cout<<str;
	std::getline(std::cin, ret);
	Contact::ClearCin();
	while (IsPrintable(ret) == 0 || ret == "")
	{
		if (ret == "")
			std::cout<<std::endl;
		std::cout<<str;
		std::getline(std::cin, ret);
		Contact::ClearCin();
	}
	return (ret);
}

int	Contact::IsPrintable(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (std::isprint(str[i]) == 0)
			return (0);}
	return (1);
}

int	Contact::IsNum(std::string str)
{
	for (int i=0; str[i] != '\0'; i++)
	{
		if (std::isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
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

	std::cout<<"|"<<std::setw(10)<<i + 1;
	str_temp = first_name;
	if (first_name.length() > 10)
	{
		str_temp = first_name.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout<<"|"<<std::setw(10)<<str_temp;
	str_temp = last_name;
	if (last_name.length() > 10)
	{
		str_temp = last_name.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout<<"|"<<std::setw(10)<<str_temp;
	str_temp = nick_name;
	if (nick_name.length() > 10)
	{
		str_temp = nick_name.substr(0, 10);
		str_temp[9] = '.';
	}
	std::cout<<"|"<<std::setw(10)<<str_temp<<"|"<<std::endl;
}

void	Contact::ClearCin()
{
	if (std::cin.eof())
	{
		std::cin.clear();
		clearerr(stdin);
	}
}