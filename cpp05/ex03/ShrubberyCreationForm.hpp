#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _name);
		ShrubberyCreationForm(ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(ShrubberyCreationForm &in);

		bool	execute(Bureaucrat const & executor) const;
};
#endif