#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <cstdlib>
# include <cmath>
# include <climits>

//알고리즘 헤더 사용해보는 과제

class Span
{
	private :
		class EmptyNumber : public std::exception
		{
			virtual const char* what() const throw();
		};
		class TooManyNumber : public std::exception
		{
			virtual const char* what() const throw();
		};
		unsigned int N;
		unsigned int idx;
		std::vector<int> store;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();
		Span& operator=(const Span &in);

		void	addNumber(int input);
		long long		shortestSpan(void);
		long long		longestSpan(void);

		template <typename T>
		void	addManyNumber(T& input)
		{
			if (this->N >= this->idx + input.size())
			{
				this->store.insert(this->store.end(), input.begin(), input.end());
				this->idx += input.size();
			}
			else
				throw Span::TooManyNumber();
		}
};


#endif