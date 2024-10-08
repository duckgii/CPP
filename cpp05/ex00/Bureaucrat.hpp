#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
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
		std::string	const name;
		int			grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &in);

		int	getGrade() const;
		std::string getName() const;

		void	IncrementGrade();
		void	DecrementGrade();
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &in);
//<<연산자는 이항 연산자이기 때문에 클래스 내부에서 선언할 수 없다.

#endif