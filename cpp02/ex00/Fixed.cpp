#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;
	this->number = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &in)
{
	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->number = in.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (number);
}

void	Fixed::setRawBits(int const raw)
{
	number = raw;
}