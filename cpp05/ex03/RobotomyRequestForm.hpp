#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _name);
		RobotomyRequestForm(RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(RobotomyRequestForm &in);

		bool	execute(Bureaucrat const & executor) const;

};
#endif