#include "Span.hpp"


const char* Span::TooManyNumber::what() const throw()
{
	return ("Invalid Index!!");
}

const char* Span::EmptyNumber::what() const throw()
{
	return ("Empty Number");
}

Span::Span() : N(0), idx(0)
{}

Span::Span(unsigned int n) : N(n), idx(0)
{}

Span::Span(const Span &copy)
{
	std::vector<int> temp;

	this->N = copy.N;
	this->idx = copy.idx;
	this->store = copy.store;
}

Span::~Span()
{}

Span& Span::operator=(const Span &in)
{
	if (this == &in)
		return (*this);
	this->N = in.N;
	this->idx = in.idx;
	this->store = in.store;
	return (*this);
}

void	Span::addNumber(int input)
{
	if (this->store.size() < N)
	{
		this->store.push_back(input);
		idx++;
	}
	else
		throw Span::TooManyNumber();
}

long long		Span::shortestSpan(void)
{
	
	long long mini = LONG_MAX;
	int	before;
	long long diff;
	std::vector<int>::iterator iter;

	if (idx == 0)
		throw Span::EmptyNumber();
	std::sort(this->store.begin(), this->store.end());
	before = *(this->store.begin());
	iter = this->store.begin();
	iter++;
	for (std::vector<int>::iterator ite = iter; ite != this->store.end(); ite++)
	{
		diff = *ite - before;
		if (diff < 0)
			diff *= -1;
		mini = std::min(mini, static_cast<long long>(diff));
		before = *ite;
	}
	return (mini);
}

long long		Span::longestSpan(void)
{
	long long maxi = 0;

	if (idx == 0)
		throw Span::EmptyNumber();
	sort(this->store.begin(), this->store.end());
	maxi = *(--this->store.end()) - *(this->store.begin());
	return (maxi);
}
