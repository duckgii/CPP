#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>
int	easyfind(T container, int find)
{
	int idx = 0;
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
	{
		if (*iter == find)
			return (idx);
		idx++;
	}
	return (-1);
}

#endif