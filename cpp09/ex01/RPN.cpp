#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(RPN const &copy)
{
	this->store = copy.getStore();
}

RPN& RPN::operator=(RPN const &in)
{
	this->store = in.getStore();
	return (*this);
}

std::stack<int>	RPN::getStore() const
{
	return (store);
}

bool	RPN::istoken(char token)
{
	if (token == '+' || token == '-' || token == '*' || token == '/')
		return (true);
	return (false);
}

void	RPN::run(std::string input)
{
	int ret;
	int num1;
	int num2;

	for (int i = 0; i < static_cast<int>(input.size()); i++)
	{
		if (input[i] == ' ')
			continue;
		if (std::isdigit(input[i]))
			store.push(input[i] - '0');
		else if (istoken(input[i]))
		{
			if (store.size() < 2)
			{
				std::cout<<"Error"<<std::endl;
				return ;
			}
			num1 = store.top();
			store.pop();
			num2 = store.top();
			store.pop();
			if (input[i] == '+')
				ret = num1 + num2;
			else if (input[i] == '-')
				ret = num2 - num1;
			else if (input[i] == '*')
				ret = num1 * num2;
			else
			{
				if (num1 == 0)
				{
					std::cout<<"Error"<<std::endl;
					return ;
				}
				ret = num2 / num1;
			}
			store.push(ret);
		}
		else
		{
			std::cout<<"Error"<<std::endl;
			return ;
		}
	}
	if (static_cast<int>(store.size()) != 1)
	{
		std::cout<<"Error"<<std::endl;
		return ;
	}
	std::cout<<store.top()<<std::endl;
}