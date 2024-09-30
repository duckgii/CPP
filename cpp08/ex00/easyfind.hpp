#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iostream>

template <typename T>
typename T::iterator	easyfind(T &container, int find) //레퍼런스 안 붙이면 임시객체의 end()가 반환돼서 main문에서 num.end()와 달라진다.
{

	return (std::find(container.begin(), container.end(), find));
}

#endif