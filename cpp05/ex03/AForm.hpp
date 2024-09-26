#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;
class AForm
{
	private:
		std::string const name;
		bool	IsSigned;
		int	const	RequiredSign;
		int	const	RequiredExecute;

	public:
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		AForm();
		AForm(std::string _name, bool issigned, int requirdsign, int requiredexecute);
		AForm(AForm &copy);
		virtual ~AForm();
		AForm& operator=(AForm &in);

		bool	getSigned() const;
		std::string getName() const;
		int		getRequiredSign() const;
		int		getRequiredExecute() const;

		void	beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream &out, const AForm &in);

#endif