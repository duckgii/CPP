#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal &in);
		virtual ~Animal();

		std::string	getType();
		virtual	void	makeSound();
};

#endif