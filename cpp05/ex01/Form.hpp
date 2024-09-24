#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;
class Form
{
	private:
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

		std::string const name;
		bool	IsSigned;
		int	const	RequiredSign;
		int	const	RequiredExecute;

	public:
		Form();
		Form(std::string _name, bool issigned, int requirdsign, int requiredexecute);
		Form(Form &copy);
		virtual ~Form();
		Form& operator=(Form &in);

		bool	getSigned() const;
		std::string getName() const;
		int		getRequiredSign() const;
		int		getRequiredExecute() const;

		bool	beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream &out, const Form &in);

#endif