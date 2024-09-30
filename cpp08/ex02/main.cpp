#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	MutantStack<int, std::list<int> > a;

	mstack.push(5);
	a.push(5);
	mstack.push(17);
	a.push(17);
	std::cout << mstack.top() << std::endl;
	std::cout << a.top() << std::endl;

	mstack.pop();
	a.pop();
	std::cout << mstack.size() << std::endl;
	std::cout << a.size() << std::endl;

	mstack.push(3);
	a.push(3);
	mstack.push(5);
	a.push(5);
	mstack.push(737);
	a.push(737);
	//[...]
	mstack.push(0);
	a.push(0);

	MutantStack<int, std::deque<int> >::iterator it1 = mstack.begin();
	MutantStack<int, std::list<int> >::iterator it2 = a.begin();
	MutantStack<int, std::deque<int> >::iterator ite1 = mstack.end();
	MutantStack<int, std::list<int> >::iterator ite2 = a.end();

	std::cout<<"here"<<std::endl;
	std::cout<<*it1<<std::endl;
	std::cout<<*it2<<std::endl;
	++it1;
	++it2;
	std::cout<<*it1<<std::endl;
	std::cout<<*it2<<std::endl;
	--it1;
	--it2;
	std::cout<<*it1<<std::endl;
	std::cout<<*it2<<std::endl;
	
	std::cout<<"mstack deque "<<std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::cout<<std::endl<<"mstack list "<<std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::cout<<std::endl<<"stack"<<std::endl; 
	std::stack<int> s(mstack);
	
	std::list<int>	real;
	real.push_back(5);
	real.push_back(17);
	std::cout << real.back() << std::endl;
	real.pop_back();
	std::cout << real.size() << std::endl;
	real.push_back(3);
	real.push_back(5);
	real.push_back(737);
	//[...]
	real.push_back(0);
	std::list<int>::iterator it = real.begin();
	std::list<int>::iterator ite = real.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	return 0;
}	