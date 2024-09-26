#include <iostream>
#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cfloat>

ScalarConverter::ScalarConverter()
{
	//std::cout<<"ScalarConverter default consructor is called";
}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
	(void)copy;
	//std::cout<<"ScalarConverter copy consructor is called";
}

ScalarConverter::~ScalarConverter()
{
	//std::cout<<"ScalarConverter default desructor is called";
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter &in)
{
	if (this == &in)
	{
		std::cout<<"Input is invalid!!"<<std::endl;
		return (*this);
	}
	//std::cout<<"ScalarConverter copy assignment operator is called";
	return (*this);
}

bool	ScalarConverter::checkValidNumber(std::string num)
{
	int flag = true;
	for (int idx = 0; idx < static_cast<int>(num.size()); idx++)
	{
		if (idx == 0 && num[idx] == '-')
			continue;
		if (isdigit(num[idx]))
			continue;
		if (num[idx] == '.')
		{
			if (flag == false)
				return (flag);
			flag = false;
			continue;
		}
		if (num[idx] == 'f' && idx == static_cast<int>(num.size()) - 1)
			return (true);
		return (false);
	}
	return (true);
}

void	ScalarConverter::convert(const char *input)
{
	double num = std::strtod(input, 0);
	std::string	in = input;

	if (in != "nan" && ((in[0] != '0' && num == 0.0) || checkValidNumber(input) == false))
	{
		std::cout<<"Input value is invalid!!!!!!"<<std::endl;
		return;
	}
	std::cout.precision(5);

	std::cout<<static_cast<char>(static_cast<int>(num))<<std::endl;
	std::cout<<"char : ";
	if (in == "nan")
		std::cout<<"impossible"<<std::endl;
	else if  (num > CHAR_MAX)
		std::cout<<"impossible"<<std::endl;
	else if (std::isprint(static_cast<char>(static_cast<int>(num))))
		std::cout<<"'"<<static_cast<char>(static_cast<int>(num))<<"'"<<std::endl;
	else
		std::cout<<"Non displayable"<<std::endl;
		
	
	std::cout<<"int : ";
	if (in == "nan")
		std::cout<<"impossible"<<std::endl;
	else if (num > INT_MAX || num < INT_MIN)
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(num)<<std::endl;

	std::cout<<"float : ";
	if (in == "nan")
		std::cout<<"nanf"<<std::endl;
	else if (num > FLT_MAX)
		std::cout<<"+inff"<<std::endl;
	else if (num < -1 * FLT_MAX)
		std::cout<<"-inff"<<std::endl;
	else
		std::cout<<num<<((static_cast<int>(num) ==  num) ? ".0f" : "f")<<std::endl;

	std::cout<<"double : ";
	if (in == "nan")
		std::cout<<"nan"<<std::endl;
	else if (num > DBL_MAX && num > 0)
		std::cout<<"inf"<<std::endl;
	else if (num < -1 * DBL_MIN)
		std::cout<<"-inf"<<std::endl;
	else
		std::cout<<static_cast<double>(num)<<((static_cast<int>(num) ==  num) ? ".0" : "")<<std::endl;
}
