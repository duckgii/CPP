#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include <string>

class Intern 
{
	public:
		Intern();
		Intern(Intern &copy);
		~Intern();
		Intern&	operator=(Intern &in);

		Form*	makeForm(std::string name, std::string target);
		static Form*	make_robo(std::string target);
		static Form*	make_shru(std::string target);
		static Form*	make_presi(std::string target);
};


#endif