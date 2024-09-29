#ifndef EASYFIND_HPP
# define EASYFIND_HPP
//이터레이터 써보라는 느낌의 과제
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