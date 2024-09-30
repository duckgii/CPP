#include "BitcoinExchange.hpp"
#include <fstream>
#include <cctype>

const char* BitcoinExchange::OpenError::what() const throw()
{
	return ("Open Error");
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

void	BitcoinExchange::dataParse(std::string line)
{
	std::string date = line.substr(0, line.find(','));
	std::string price = line.substr(line.find(',') + 1);
	std::string year;
	std::string month;
	std::string day;

	year = line.substr(0, line.find('-'));
	if (year.length() != 4)
	{
		this->wrongInputStyle();
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!isdigit(year[i]))
		{
			this->wrongInputStyle();
			return ;
		}
	}
	line = line.substr(line.find('-') + 1);
}

void	BitcoinExchange::getData(void)
{
	std::string	line;
	std::ifstream	readFile;

	readFile.open("data.csv");
	if (readFile.is_open())
	{
		getline(readFile, line);
		if (line != "date,exchange_rate")
		{
			this->wrongInputStyle(); //-> 못 읽었을 경우에는 다음 파싱에서도 에러처리 해야함
			readFile.close();
			return ;
		}
		while (!readFile.eof())
		{
			getline(readFile, line);
			dataParse(line);
		}
		readFile.close();
	}
	else
		throw OpenError();
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

void	BitcoinExchange::readFile(std::string filename)
{
	std::string	line;
	std::ifstream	readFile;

	readFile.open(filename.c_str());
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			getline(readFile, line);
		}
		readFile.close();
	}
	else
		throw OpenError();
}
