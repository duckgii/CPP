#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string _type);
		~Animal();
		Animal(Animal &copy);
		Animal& operator=(const Animal &in);

		virtual	void	makeSound();
};

#endif