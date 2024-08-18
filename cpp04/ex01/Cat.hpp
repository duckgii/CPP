#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &in);
		virtual ~Cat();

		virtual	void	makeSound();
};

#endif