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

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> >	container_v;
		std::list<std::pair<int, int> > container_l;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe& operator=(PmergeMe const &in);
		void	inputData(std::string input);
		void	runVector();
		void	runlist();
		std::vector<std::pair<int, int> > recur_v(std::vector<std::pair<int, int> > input);
		std::vector<std::pair<int, int> > getContainer_v() const;
};

#endif