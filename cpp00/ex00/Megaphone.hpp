#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#include <iostream>
#include <string>

class	Megaphone
{
	private:
		std::string	upper_str;
	public:
		std::string	UpperCase(std::string input);
		void Noise();
};

#endif