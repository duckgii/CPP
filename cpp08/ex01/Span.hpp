#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <cstdlib>
# include <cmath>
//알고리즘 헤더 사용해보는 과제
class Span
{
	private :
		class TooManyNumber : public std::exception
		{
			virtual const char* what() const throw();
		};
		unsigned int N;
		std::vector<int> store;
	public:
		Span();
		Span(unsigned int n);
		Span(Span &copy);
		~Span();
		Span& operator=(Span &in);

		void	addNumber(int input);
		void	addManyNumber(int input);
		long long		shortestSpan(void);
		long long		longestSpan(void);
};

#endif