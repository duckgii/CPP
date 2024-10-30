#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &in)
{
	this->container_v = in.getContainer_v();
	return (*this);
}

void	PmergeMe::inputData(std::string input)
{
	std::stringstream ss;
	std::string num;
	int i = 0;

	ss<<input;
	while (getline(ss, num, ' '))
	{
		container_v.push_back(std::make_pair(std::atoi(num.c_str()), i));
		container_d.push_back(std::make_pair(std::atoi(num.c_str()), i));
		i++;
	}
}

void	PmergeMe::runVector()
{
	std::vector<std::pair<int, int> > ret;
	clock_t	start, finish;

	std::cout<<"Before: ";
	for (int i = 0; i < static_cast<int>(container_v.size()); i++)
	{
		std::cout<<container_v[i].first<<" ";
	}
	std::cout<<std::endl;
	start = clock();
	ret = recur_v(container_v);
	finish = clock();
	std::cout<<"After:  ";
	for (int i = 0; i < static_cast<int>(ret.size()); i++)
	{
		std::cout<<ret[i].first<<" ";
	}
	std::cout<<"\n";
	std::cout<<"Time to process a range of 5 elements with std::vector : "<<static_cast<double>((finish - start) / static_cast<double>(100))<<" ms"<<std::endl;
}

bool cmp(int b, std::pair<int, int> a)
{
	return (a.first > b);
}

std::vector<std::pair<int, int> > PmergeMe::doInsert_v(std::vector<std::pair<int, int> > check, std::vector<std::pair<int, int> > main, std::vector<std::pair<int, int> > sub)
{
	std::vector<std::pair<int, int> >	ret = check;
	int		yacop = 1;
	int 	pre = -1;
	int 	t = 0;
	int 	idx = 0;

	for (int i = 0 ;i < static_cast<int>(main.size()); i++)
	{
		ret[i].second = main[ret[i].second].second;
	}
	for (int count = 0; count < static_cast<int>(check.size()); count++)
	{
		if (idx == pre)
		{
			pre = t;
			yacop += 1;
			idx = std::pow(2, yacop) - count - 1;
			t = idx;
		}
		if (idx >= static_cast<int>(check.size()))
			idx = check.size() - 1;
		ret.insert(upper_bound(ret.begin(), ret.begin() + std::min(static_cast<int>(ret.size()), static_cast<int>(std::pow(2, yacop))), sub[check[idx].second].first, cmp), sub[check[idx].second]);
		idx--;
	}
	if (main.size() < sub.size())
		ret.insert(upper_bound(ret.begin(), ret.end(), sub[sub.size() - 1].first, cmp), sub[sub.size() - 1]);
	return (ret);
}

std::vector<std::pair<int, int> > PmergeMe::recur_v(std::vector<std::pair<int, int> > input)
{
	std::vector<std::pair<int, int> > main;
	std::vector<std::pair<int, int> > sub;
	std::vector<std::pair<int, int> > ret;
	std::vector<std::pair<int, int> > check;

	for (int idx = 0; idx < static_cast<int>(input.size()); idx++)
	{
		if (idx % 2 == 0 && idx + 1 == static_cast<int>(input.size()))
			sub.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 0 && input[idx].first == input[idx + 1].first)
			main.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 1 && input[idx].first == input[idx - 1].first)
			sub.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 0 && input[idx].first > input[idx + 1].first)
			main.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 1 && input[idx].first > input[idx - 1].first)
			main.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 0 && input[idx].first < input[idx + 1].first)
			sub.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 1 && input[idx].first < input[idx - 1].first)
			sub.push_back(std::make_pair(input[idx].first, idx));
	}
	if (main.size() <= 1)
	{
		if (sub.size() > 0)
			main.insert(main.begin(), sub[0]);
		if (sub.size() > 1)
			main.insert(std::upper_bound(main.begin(), main.end(), sub[1].first, cmp), sub[1]);
		return (main);
	}
	check = recur_v(main);
	ret = doInsert_v(check, main, sub);
	return (ret);
}

std::deque<std::pair<int, int> > PmergeMe::recur_d(std::deque<std::pair<int, int> > input)
{
	std::deque<std::pair<int, int> > main;
	std::deque<std::pair<int, int> > sub;
	std::deque<std::pair<int, int> > ret;
	std::deque<std::pair<int, int> > check;

	for (int idx = 0; idx < static_cast<int>(input.size()); idx++)
	{
		if (idx % 2 == 0 && idx + 1 == static_cast<int>(input.size()))
			sub.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 0 && input[idx].first == input[idx + 1].first)
			main.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 1 && input[idx].first == input[idx - 1].first)
			sub.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 0 && input[idx].first > input[idx + 1].first)
			main.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 1 && input[idx].first > input[idx - 1].first)
			main.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 0 && input[idx].first < input[idx + 1].first)
			sub.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 1 && input[idx].first < input[idx - 1].first)
			sub.push_back(std::make_pair(input[idx].first, idx));
	}
	if (main.size() <= 1)
	{
		if (sub.size() > 0)
			main.insert(main.begin(), sub[0]);
		if (sub.size() > 1)
			main.insert(std::upper_bound(main.begin(), main.end(), sub[1].first, cmp), sub[1]);
		return (main);
	}
	check = recur_d(main);
	ret = doInsert_d(check, main, sub);
	return (ret);
}

std::deque<std::pair<int, int> > PmergeMe::doInsert_d(std::deque<std::pair<int, int> > check, std::deque<std::pair<int, int> > main, std::deque<std::pair<int, int> > sub)
{
	std::deque<std::pair<int, int> >	ret = check;
	int		yacop = 1;
	int 	pre = -1;
	int 	t = 0;
	int 	idx = 0;

	for (int i = 0 ;i < static_cast<int>(main.size()); i++)
	{
		ret[i].second = main[ret[i].second].second;
	}
	for (int count = 0; count < static_cast<int>(check.size()); count++)
	{
		if (idx == pre)
		{
			pre = t;
			yacop += 1;
			idx = std::pow(2, yacop) - count - 1;
			t = idx;
		}
		if (idx >= static_cast<int>(check.size()))
			idx = check.size() - 1;
		ret.insert(upper_bound(ret.begin(), ret.begin() + std::min(static_cast<int>(ret.size()), static_cast<int>(std::pow(2, yacop))), sub[check[idx].second].first, cmp), sub[check[idx].second]);
		idx--;
	}
	if (main.size() < sub.size())
		ret.insert(upper_bound(ret.begin(), ret.end(), sub[sub.size() - 1].first, cmp), sub[sub.size() - 1]);
	return (ret);
}

void	PmergeMe::rundeque()
{
	std::deque<std::pair<int, int> > ret;
	clock_t	start, finish;
	
	start = clock();
	ret = recur_d(container_d);
	finish = clock();
	std::cout<<"Time to process a range of 5 elements with std::deque : "<<static_cast<double>((finish - start) / static_cast<double>(100))<<" ms"<<std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::getContainer_v() const
{
	return (container_v);
}