#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &in);
		virtual ~Dog();

		virtual	void	makeSound();
};

#endif