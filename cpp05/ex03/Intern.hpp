#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern 
{
	public:
		Intern();
		Intern(Intern &copy);
		~Intern();
		Intern&	operator=(Intern &in);

		AForm*	makeForm(std::string name, std::string target);
		static AForm*	make_robo(std::string target);
		static AForm*	make_shru(std::string target);
		static AForm*	make_presi(std::string target);
};


#endif