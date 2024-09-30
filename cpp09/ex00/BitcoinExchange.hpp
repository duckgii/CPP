#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>

class BitcoinExchange
{
	private:
		class	OpenError : std::exception
		{
			virtual const char* what() const throw();
		};
		std::map<std::string, float>	data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &in);

		void	getData(void);
		void	dataParse(std::string line);
		void	dateBadInput(std::string error);
		void	negativeNumError(void);
		void	tooLargeError(void);
		void	wrongInputStyle(void);
		void	readFile(std::string filename);
};

#endif