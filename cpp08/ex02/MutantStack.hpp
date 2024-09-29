#ifndef MITANTSTACK_HPP
# define MITANTSTACK_HPP

#include <stack>
#include <algorithm>

//각 컨테이너의 내부 구조를 공부하라는 것 같은 과제.

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack() {}

		~MutantStack() {}

		MutantStack(MutantStack &copy) 
		{
			this->c = copy.c; // stack 까보면 container type이 c로 되어있음 근데 사실 deque이다.
		}

		MutantStack& operator=(MutantStack &in) 
		{
			if (this == &in)
				return (*this);
			this->c = in.c;
			return (*this);
		}

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}
};


#endif