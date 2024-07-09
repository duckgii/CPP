#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstdio>
#include <iostream>
#include <string>
#include "Contact.hpp"


class	PhoneBook
{
	private:
		Contact contact[8];
		int		idx;
		int		booklen;
		int		checkfirst;
	public:
		PhoneBook();
		void	AddContact();
		void	DisplayContact();
		void	SearchIndex();
};

#endif