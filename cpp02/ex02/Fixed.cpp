#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout<<"Int constructor called"<<std::endl;
	number = input << myraw;
}

Fixed::Fixed(const float input)
{
	std::cout<<"Float constructor called"<<std::endl;
	number = roundf(input * 256);
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=(const Fixed &in)
{

	if (this == &in)
	{
		std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	std::cout<<"Copy assignment operator called"<<std::endl;
	number = in.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &in)
{
	out<<in.toFloat();
	return (out);
}

int	Fixed::getRawBits(void) const
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	return (number);
}

void	Fixed::setRawBits(int const raw)
{
	number = raw;
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> myraw);
}

float	Fixed::toFloat(void) const
{
	return (getRawBits() / (float)256);
}