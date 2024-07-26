#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <algorithm>

class Fixed
{
	private:
		int number;
		static const int myraw = 8;
	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &copy);
		~Fixed();

		Fixed&	operator=(const Fixed &in);
		Fixed&	operator++();
		Fixed&	operator--();
		const Fixed	operator++(int);
		const Fixed	operator--(int);
		Fixed	operator*(const Fixed &in) const;
		Fixed	operator/(const Fixed &in) const;
		Fixed	operator+(const Fixed &in) const;
		Fixed	operator-(const Fixed &in) const;
		int	operator<(const Fixed &in) const;
		int	operator>(const Fixed &in) const;
		int	operator<=(const Fixed &in) const;
		int	operator>=(const Fixed &in) const;
		int	operator==(const Fixed &in) const;
		int	operator!=(const Fixed &in) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream &out, const Fixed &in);
#endif