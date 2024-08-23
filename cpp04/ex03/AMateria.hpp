#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class ICharacter;
class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria &copy);
		AMateria(const std::string & type);
		AMateria& operator=(const AMateria &in);

		std::string const & getType() const; //Returns the materia type
		void	setType(const std::string input);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif