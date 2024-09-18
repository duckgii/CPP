#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;
class Form
{
	private:
		std::string const name;
		bool	IsSigned;
		int	const	RequiredSign;
		int	const	RequiredExecute;

	public:
		Form();
		Form(std::string _name, bool issigned, int requirdsign, int requiredexecute);
		Form(Form &copy);
		~Form();
		Form& operator=(Form &in);

		bool	getSigned() const;
		std::string getName() const;
		int		getRequiredSign() const;
		int		getRequiredExecute() const;

		bool	beSigned(Bureaucrat &bureaucrat);
		void	GradeTooHighException(std::string option, int value);
		void	GradeTooLowException(std::string option, int value);
};

std::ostream& operator<<(std::ostream &out, const Form &in);

#endif