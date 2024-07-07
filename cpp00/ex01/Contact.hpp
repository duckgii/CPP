#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
//#include <iomanip>

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void	InitContact();
		void	DisplayContact(int i);
		void	DisplayAllInfo();
		//void	DeleteContact(int idx);
};

#endif