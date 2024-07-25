#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int number;
		static const int myraw = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed& operator=(const Fixed &in);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif