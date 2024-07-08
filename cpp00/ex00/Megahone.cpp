/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megahone.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:54:40 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/08 18:56:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class	Megaphone
{
	private:
		std::string	upper_str;
	public:
		std::string	UpperCase(std::string input);
		void Noise();
};

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

int main(int ac, char *av[])
{
	Megaphone	obj;

	if (ac == 1)
	{
		obj.Noise();
		return (0);
	}
	else
	{
		for (int idx = 1; av[idx] != NULL; idx++)
		{
			std::cout<<obj.UpperCase(av[idx])<<" ";
		}
		std::cout<<std::endl;
	}
	return (0);
}
