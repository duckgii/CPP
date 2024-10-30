#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>

class BitcoinExchange
{
	private:
		class	OpenErrorException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		class	WrongInputException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		std::map<int, double>	data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &in);

		void	find_data(int date, double value, std::string date_s);
		void	getData(std::string filename, int mode);
		void	dataParse(std::string line, int mode);
		int		get_date(std::string &line);
		bool	check_value(std::string num);
		
		int		dateError(std::string	errmsg);
		void	dateBadInput(std::string error);
		void	negativeNumError(void);
		void	tooLargeError(void);
		void	wrongInputStyle(void);
};

#endif