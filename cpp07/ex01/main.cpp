#include "iter.hpp"

template <typename T>
void	print(T in)
{
	std::cout<<in;
}

int main()
{
	int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	::iter(num, 10, print<int>);
	std::cout<<std::endl;
}