#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
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