#include "Megaphone.hpp"

std::string	Megaphone::UpperCase(std::string input)
{
	int	idx = 0;
	int	len = input.length();

	upper_str = input;
	for(idx = 0; idx < len; idx++)
	{
		upper_str[idx] = std::toupper(input[idx]);
	}
	return (upper_str);
}
void	Megaphone::Noise()
{
	std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
}
