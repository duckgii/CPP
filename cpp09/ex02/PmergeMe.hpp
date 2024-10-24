#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <utility>
# include <sstream>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <list>
# include <ctime>
# include <deque>

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> >	container_v;
		std::deque<std::pair<int, int> > container_d;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe& operator=(PmergeMe const &in);
		void	inputData(std::string input);
		void	runVector();
		void	rundeque();
		std::vector<std::pair<int, int> > recur_v(std::vector<std::pair<int, int> > input);
		std::deque<std::pair<int, int> > recur_d(std::deque<std::pair<int, int> > input);
		std::vector<std::pair<int, int> > getContainer_v() const;
};

#endif