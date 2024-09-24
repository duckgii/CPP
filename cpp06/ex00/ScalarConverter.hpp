#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <string>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter& operator=(ScalarConverter &in);

		void	convert(const char *input);
		bool	checkValidNumber(std::string num);
};


#endif
