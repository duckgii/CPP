#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _name);
		RobotomyRequestForm(RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(RobotomyRequestForm &in);

		void	execute(Bureaucrat const & executor) const;

};
#endif