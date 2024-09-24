#include <iostream>
#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <limits>
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

	if (num == 0.0 || checkValidNumber(input) == false)
	{
		std::cout<<"Input value is invalid!!!!!!"<<std::endl;
		return;
	}
	std::cout.precision(10);	
	std::cout<<"char : ";
	if (std::isprint(static_cast<int>(num)))
		std::cout<<static_cast<char>(static_cast<int>(num))<<std::endl;
	else
		std::cout<<"Non displayable"<<std::endl;
	
	std::cout<<"int : ";
	if (num > INT_MAX || num < INT_MIN)
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(num)<<std::endl;

	std::cout<<"float : ";
	if (num > FLT_MAX)
		std::cout<<"+inff"<<std::endl;
	else if (num < -1 * FLT_MAX)
		std::cout<<"-inff"<<std::endl;
	else
		std::cout<<num<<((in.find(".") ==  std::string::npos) ? ".0f" : "f")<<std::endl;

	std::cout<<"double : ";
	if (num > FLT_MAX && num > 0)
		std::cout<<"inf"<<std::endl;
	if (num < FLT_MIN)
		std::cout<<"-inf"<<std::endl;
	else
		std::cout<<static_cast<double>(num)<<((in.find(".") ==  std::string::npos) ? ".0" : "")<<std::endl;
}
