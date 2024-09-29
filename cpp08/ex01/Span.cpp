#include "Span.hpp"


const char* Span::TooManyNumber::what() const throw()
{
	return ("Invalid Index!!");
}

Span::Span() : N(0)
{}

Span::Span(unsigned int n) : N(n)
{}

Span::Span(Span &copy)
{
	std::vector<int> temp;

	this->N = copy.N;
	for (std::vector<int>::iterator iter = copy.store.begin(); iter != copy.store.end(); iter++)
	{
		this->store.push_back(*iter);
	}
}

Span::~Span()
{}

Span& Span::operator=(Span &in)
{
	std::vector<int> temp;

	if (this == &in)
		return (*this);
	this->N = in.N;
	for (std::vector<int>::iterator iter = in.store.begin(); iter != in.store.end(); iter++)
	{
		this->store.push_back(*iter);
	}
	return (*this);
}

void	Span::addNumber(int input)
{
	if (this->store.size() < N)
	{
		this->store.push_back(input);
	}
	else
		throw TooManyNumber();
}

void	Span::addManyNumber(int input)
{
	for (int i = 0; i < input ;i ++)
	{
		addNumber(rand() % INT_MAX);
	}
}

long long		Span::shortestSpan(void)
{
	long long mini = INT_MAX;
	int	before = *(this->store.begin());
	long long diff;

	sort(this->store.begin(), this->store.end());
	for (std::vector<int>::iterator iter = ++(this->store.begin()); iter != this->store.end(); iter++)
	{
		diff = *iter - before;
		if (diff < 0)
			diff *= -1;
		mini = std::min(mini, static_cast<long long>(diff));
		before = *iter;
	}
	return (mini);
}

long long		Span::longestSpan(void)
{
	long long maxi = 0;
	int	before = *(this->store.begin());

	sort(this->store.begin(), this->store.end());
	for (std::vector<int>::iterator iter = ++(this->store.begin()); iter != this->store.end(); iter++)
	{
		maxi = std::max(maxi, static_cast<long long>(*iter - before));
		before = *iter;
	}
	return (maxi);
}
