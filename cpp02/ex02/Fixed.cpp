#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	//std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int input)
{
	//std::cout<<"Int constructor called"<<std::endl;
	number = input << myraw;
}

Fixed::Fixed(const float input)
{
	//std::cout<<"Float constructor called"<<std::endl;
	number = roundf(input * 256);
}

Fixed::~Fixed()
{
	//std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout<<"Copy constructor called"<<std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=(const Fixed &in)
{

	if (this == &in)
	{
		//std::cout<<"Invalid input!"<<std::endl;
		return (*this);
	}
	//std::cout<<"Copy assignment operator called"<<std::endl;
	number = in.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &in)
{
	out<<in.toFloat();
	return (out);
}

Fixed&	Fixed::operator++()
{
	number += 1;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	retobj(this->toFloat());
	number += 1;
	return (retobj);
}

Fixed&	Fixed::operator--()
{
	number -= 1;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	Fixed	retobj(this->toFloat());
	number -= 1;
	return (retobj);
}

Fixed	Fixed::operator+(const Fixed &in) const
{
	Fixed	ret(this->toFloat() + in.toFloat());
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &in) const
{
	Fixed	ret(this->toFloat() - in.toFloat());
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &in) const
{
	Fixed	ret(this->toFloat() * in.toFloat());
	return (ret);
}

Fixed	Fixed::operator/(const Fixed &in) const
{
	Fixed	ret(this->toFloat() / in.toFloat());
	return (ret);
}

int	Fixed::operator>(const Fixed &in) const
{
	return(this->number > in.number);
}

int	Fixed::operator<(const Fixed &in) const
{
	return(this->number < in.number);
}

int	Fixed::operator<=(const Fixed &in) const
{
	return(this->number <= in.number);
}

int	Fixed::operator>=(const Fixed &in) const
{
	return(this->number >= in.number);
}

int	Fixed::operator==(const Fixed &in) const
{
	return(this->number == in.number);
}

int	Fixed::operator!=(const Fixed &in) const
{
	return(this->number != in.number);
}

int	Fixed::getRawBits(void) const
{
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.number >= b.number)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	Fixed	ret(0);
	if (a.number >= b.number)
		return (b);
	return (a);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.number >= b.number)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.number >= b.number)
		return (a);
	return (b);
}
