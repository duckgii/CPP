#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 25, 5)
{
	std::cout<<"ShrubberyCreationForm default constructor is called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name) : AForm(_name, false, 25, 5) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout<<"ShrubberyCreationForm copy constructor is called"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm default destructor is called"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &in)
{
	if (this == &in)
	{
		std::cout<<"input is invalid!"<<std::endl;
		return (*this);
	}
	std::cout<<"ShrubberyCreationForm copy assignment operator is called"<<std::endl;
	return (*this);
}

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	readFile;
	std::string		filename;

	try
	{
		if (executor.getGrade() > this->getRequiredExecute())
			throw executor.getGrade();
		filename = this->getName() + "_shrubbery";
		readFile.open(filename);
		if (readFile.is_open())
		{
			readFile << "       ,@@@@@@@, \n";
			readFile << "  ,,,.   ,@@@@@@/@@,  .oo8888o. \n";
			readFile << ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
			readFile << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
			readFile << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
			readFile << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
			readFile << "`&%\\ ` /%&'    |.|        \\ '|8'\n";
			readFile << "    |o|        | |         | |\n";
			readFile << "    |.|        | |         | |\n";
			readFile << " \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
		}
		else
		{
			std::cout<<"File open error"<<std::endl;
			return (false);
		}
		readFile.close();
		return (true);
	}
	catch(const int grade)
	{
		this->GradeTooLowException("RequiredSign", grade);
		return (false);
	}
}