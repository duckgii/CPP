#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string		*ideas;
	public:
		Brain();
		Brain(const Brain &copy);
		Brain& operator=(const Brain &in);
		virtual ~Brain();
};

#endif