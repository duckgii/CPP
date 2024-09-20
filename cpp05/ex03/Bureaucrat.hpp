#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Form;

class Bureaucrat
{
	private:
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
		void	signForm(Form &form);
		void	executeForm(Form const & form);

		void	IncrementGrade();
		void	DecrementGrade();
		void	GradeTooHighException();
		void	GradeTooLowException();
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &in);
//<<연산자는 이항 연산자이기 때문에 클래스 내부에서 선언할 수 없다.

#endif