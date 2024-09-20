#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _name);
		PresidentialPardonForm(PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(PresidentialPardonForm &in);

		bool	execute(Bureaucrat const & executor) const;
};
#endif