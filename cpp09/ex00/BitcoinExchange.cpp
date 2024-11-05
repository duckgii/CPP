#include "BitcoinExchange.hpp"
#include <fstream>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <climits>

const char* BitcoinExchange::OpenErrorException::what() const throw()
{
	return ("Error: could not open file.");
}

const char* BitcoinExchange::WrongInputException::what() const throw()
{
	return ("Error : wrong input style.");
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->data = copy.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &in)
{
	if (this == &in)
		return (*this);
	this->data = in.data;
	return (*this);
}

bool check_yoon(int year)
{
	if (year % 4 == 0)
	{
		if (year % 400 == 0)
			return (true);
		if (year % 100 == 0)
			return (false);
		return (true);
	}
	return (false);
}

int	BitcoinExchange::dateError(std::string	errmsg)
{
	this->dateBadInput(errmsg);
	return (0);
}

int	BitcoinExchange::get_date(std::string &line)
{
	std::stringstream input_date;
	std::string	date;
	std::string	temp;
	std::string error;
	int	check_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int check;
	int	ret;

	error = line;
	input_date<<line;
	for (int i = 0; i < 3; i++)
	{
		getline(input_date, temp, '-');
		if (temp == "")
			return (this->dateError(error));
		date += temp;
	}
	if (getline(input_date, temp, '-') || static_cast<int>(date.length()) != 8)
		return (this->dateError(error));
	for (int i = 0; i < 8; i++)
	{
		if (!isdigit(date[i]))
			return (this->dateError(error));
	}
	ret = std::atoi(date.c_str());
	if (ret / 10000 > 2024 || (ret % 10000) / 100 > 12)
		return (this->dateError(error));
	check = ret % 100;
	if (check > check_day[(ret % 10000) / 100])
	{
		if (check_yoon(ret / 10000))
		{
			if ((ret % 10000) / 100 == 2 && check > 29)
				return (this->dateError(error));
		}
		else
			return (this->dateError(error));
	}
	return (ret);
}

void	BitcoinExchange::find_data(int date, double value, std::string date_s)
{
	double pre_value = data.begin()->second;

	for (std::map<int, double>::iterator ite = data.begin(); ite != data.end(); ite++)
	{
		if (date < ite->first)
			break;
		pre_value = ite->second;
		if (date == ite->first)
			break;
	}
	std::cout<<date_s<<" => "<<value<<" = "<<static_cast<double>(value * pre_value)<<std::endl;
}

void	BitcoinExchange::dataParse(std::string line, int mode)
{
	std::stringstream 	all_input;
	std::string			date_line;
	std::string 		value_s;
	std::string 		error;
	double 				value_f;
	char				dilimiter;
	int					date = 0;

	dilimiter = (mode == 1 ? ',' : ' ');
	all_input<<line;
	getline(all_input, date_line, dilimiter);
	error = date_line;
	date = get_date(date_line);
	if (date == 0)
		return ;
	if (mode == 2)
	{
		getline(all_input, date_line, dilimiter);
		if (date_line != "|")
			return(this->dateBadInput(line));
	}
	getline(all_input, value_s, dilimiter);
	if (check_value(value_s) == false)
		return ;
	value_f = std::strtod(value_s.c_str(), 0);
	if (getline(all_input, value_s, dilimiter) || value_s.length() == 0)
		return (this->dateBadInput(line));
	if (mode == 2 && date < data.begin()->first)
		return (this->dateBadInput(error));
	if (mode == 1)
		this->data.insert(std::make_pair(date, value_f));
	else
		find_data(date, value_f, error);
	return ;
}

void	BitcoinExchange::getData(std::string filename, int mode)
{
	std::string		line;
	std::ifstream	readFile;

	readFile.open(filename.c_str());
	if (readFile.is_open())
	{
		getline(readFile, line);
		if ((mode == 1 && line != "date,exchange_rate") || (mode == 2 && line != "date | value"))
		{
			readFile.close();
			throw BitcoinExchange::WrongInputException();
		}
		while (!readFile.eof())
		{
			getline(readFile, line);
			if (line == "")
				break;
			dataParse(line, mode);
		}
		readFile.close();
	}
	else
		throw BitcoinExchange::OpenErrorException();
}

bool	BitcoinExchange::check_value(std::string num)
{
	double value = std::strtod(num.c_str(), 0);
	int flag = true;

	for (int idx = 0; idx < static_cast<int>(num.size()); idx++)
	{
		if ((idx == 0 && num[idx] == '-') || isdigit(num[idx]))
			continue;
		if (num[idx] == '.')
		{
			if (flag == false)
			{
				this->dateBadInput(num);
				return (false);
			}
			flag = false;
			continue;
		}
		this->dateBadInput(num);
		return (false);
	}
	if  (value > INT_MAX)
	{
		tooLargeError();
		return (false);
	}
	else if (value < 0)
	{
		negativeNumError();
		return (false);
	}
	return (true);
}

void	BitcoinExchange::dateBadInput(std::string error)
{
	std::cerr<<"Error: bad input => "<<error<<std::endl;
}

void	BitcoinExchange::negativeNumError(void)
{
	std::cerr<<"Error: not a positive number."<<std::endl;
}

void	BitcoinExchange::tooLargeError(void)
{
	std::cerr<<"Error: too large a number."<<std::endl;
}

void	BitcoinExchange::wrongInputStyle(void)
{
	std::cerr<<"Error : wrong input style."<<std::endl;
}


