#ifndef MITANTSTACK_HPP
# define MITANTSTACK_HPP

#include <stack>
#include <algorithm>

//각 컨테이너의 내부 구조를 공부하라는 것 같은 과제.

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		typedef typename C::iterator iterator;
		typedef typename C::const_iterator const_iterator;
		typedef typename C::reverse_iterator reverse_iterator;
		typedef typename C::const_reverse_iterator const_reverse_iterator;

	    //typedef typename __base::iterator              iterator;
	    //typedef typename __base::const_iterator        const_iterator;

	    //typedef _VSTD::reverse_iterator<iterator>       reverse_iterator;
	    //typedef _VSTD::reverse_iterator<const_iterator> const_reverse_iterator;

		MutantStack() {}

		~MutantStack() {}

		MutantStack(const MutantStack &copy) 
		{
			this->c = copy.c; // stack 까보면 container type이 c로 되어있음 근데 사실 deque이다.
		}

		MutantStack& operator=(const MutantStack &in) 
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
		const_iterator	begin() const
		{
			return (this->c.begin());
		}
		reverse_iterator	rbegin()
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator	rbegin() const
		{
			return (this->c.rbegin());
		}

		iterator	end()
		{
			return (this->c.end());
		}
		const_iterator	end() const
		{
			return (this->c.end());
		}
		reverse_iterator	rend()
		{
			return (this->c.rend());
		}
		const_reverse_iterator	rend() const
		{
			return (this->c.rend());
		}
};


#endif