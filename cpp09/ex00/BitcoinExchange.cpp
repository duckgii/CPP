#include "BitcoinExchange.hpp"
#include <fstream>
#include <cctype>
#include <sstream>

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

int	BitcoinExchange::get_date(std::string &line)
{
	std::stringstream input_date;
	std::stringstream ss;
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
		{
			this->dateBadInput(error);
			return (0);
		}
		date += temp;
	}
	if (getline(input_date, temp, '-'))
	{
		this->dateBadInput(error);
		return (0);
	}
	if (static_cast<int>(date.length()) != 8)
	{
		this->dateBadInput(error);
		return (0);
	}
	for (int i = 0; i < 8; i++)
	{
		if (!isdigit(date[i]))
		{
			this->dateBadInput(error);
			return (0);
		}
	}
	ss<<date;
	ss>>ret;
	if (ret / 10000 > 2024 || (ret % 10000) / 100 > 12)
	{
		this->dateBadInput(error);
		return (0);
	}
	check = ret % 100;
	if (check > check_day[(ret % 10000) / 100])
	{
		if (check_yoon(ret / 10000))
		{
			if ((ret % 10000) / 100 == 2 && check > 29)
			{
				this->dateBadInput(error);
				return (0);
			}
		}
		else
		{
			this->dateBadInput(error);
			return (0);
		}
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
	}
	std::cout<<date_s<<" => "<<value<<" = "<<static_cast<double>(value * pre_value)<<std::endl;
}

void	BitcoinExchange::dataParse(std::string line, int mode)
{
	std::stringstream all_input;
	std::string		date_line;
	std::string value_s;
	std::string error;
	double 		value_f;
	char	dilimiter;
	std::string	temp;
	int	date = 0;

	if (mode == 1)
		dilimiter = ',';
	else
		dilimiter = ' ';
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
		{
			this->dateBadInput(line);
			return ;
		}
	}
	getline(all_input, value_s, dilimiter);
	if (check_value(value_s) == false)
		return ;
	value_f = std::strtod(value_s.c_str(), 0);
	if (getline(all_input, value_s, dilimiter) || value_s.length() == 0)
	{
		this->dateBadInput(line);
		return ;
	}
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

	//std::cout<<"hi"<<std::endl;
	readFile.open(filename);
	if (readFile.is_open())
	{
		getline(readFile, line);
		if ((mode == 1 && line != "date,exchange_rate") || (mode == 2 && line != "date | value"))
		{
			readFile.close();
			throw BitcoinExchange::WrongInputException(); //-> 못 읽었을 경우에는 다음 파싱에서도 에러처리 해야함 ...?
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
		if (idx == 0 && num[idx] == '-')
			continue;
		if (isdigit(num[idx]))
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
	std::cout<<"Error: bad input => "<<error<<std::endl;
}

void	BitcoinExchange::negativeNumError(void)
{
	std::cout<<"Error: not a positive number."<<std::endl;
}

void	BitcoinExchange::tooLargeError(void)
{
	std::cout<<"Error: too large a number."<<std::endl;
}

void	BitcoinExchange::wrongInputStyle(void)
{
	std::cout<<"Error : wrong input style."<<std::endl;
}


