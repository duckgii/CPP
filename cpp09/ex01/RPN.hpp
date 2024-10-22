#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <cctype>
# include <iostream>
# include <cstdlib>

class RPN
{
	private:
		std::stack<int>	store;
	public:
		RPN();
		~RPN();
		RPN(RPN const &copy);
		RPN& operator=(RPN const &in);
		std::stack<int>	getStore() const;
		void	run(std::string input);
		bool	istoken(char token);
};

#endif