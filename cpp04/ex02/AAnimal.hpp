#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal& operator=(const AAnimal &in);
		virtual ~AAnimal();

		std::string	getType();
		virtual	void	makeSound() = 0;
};

#endif