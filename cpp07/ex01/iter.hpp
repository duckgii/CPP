#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename func>
void	iter(T first, int len, func f)
{
	for (int i = 0; i < len; i++)
	{
		(*f)(*(first + i));
	}
}
#endif