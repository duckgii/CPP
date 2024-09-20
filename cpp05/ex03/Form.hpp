#ifndef Form_HPP
# define Form_HPP

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
		virtual ~Form();
		Form& operator=(Form &in);

		bool	getSigned() const;
		void	setSigned();
		std::string getName() const;
		int		getRequiredSign() const;
		int		getRequiredExecute() const;

		bool	beSigned(Bureaucrat &bureaucrat);
		void	GradeTooHighException(std::string option, int value) const;
		void	GradeTooLowException(std::string option, int value) const;
		virtual bool	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &out, const Form &in);

#endif