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

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> >	container_v;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe& operator=(PmergeMe const &in);
		void	inputData(std::string input);
		void	runVector();
		void	runDeque();
		std::vector<std::pair<int, int> > recur(std::vector<std::pair<int, int> > input);
		std::vector<std::pair<int, int> > getContainer_v() const;
};

#endif