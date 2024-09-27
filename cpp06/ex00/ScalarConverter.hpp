#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <string>

// static_cast는 c의 명시적 형변환과 동일하다고 생각하면 된다.

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
