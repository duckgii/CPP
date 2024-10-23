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
		i++;
	}
}

void	PmergeMe::runVector()
{
	std::vector<std::pair<int, int> > ret;

	for (int i = 0; i < static_cast<int>(container_v.size()); i++)
	{
		std::cout<<container_v[i].first<<" ";
	}
	std::cout<<std::endl;
	ret = recur(container_v);
	for (int i = 0; i < static_cast<int>(ret.size()); i++)
	{
		std::cout<<ret[i].first<<" ";
	}
	std::cout<<"\n";
}

bool cmp(int b, std::pair<int, int> a)
{
	return (a.first > b);
}

std::vector<std::pair<int, int> > PmergeMe::recur(std::vector<std::pair<int, int> > input)
{
	std::vector<std::pair<int, int> > main;
	std::vector<std::pair<int, int> > sub;
	std::vector<std::pair<int, int> > ret;
	std::vector<std::pair<int, int> > check;
	int		yacop = 1;
	int		offset = 1;

	for (int idx = 0; idx < static_cast<int>(input.size()); idx++)
	{
		if (idx % 2 == 0 && idx + 1 == static_cast<int>(input.size()))
			sub.push_back(input[idx]);
		else if (idx % 2 == 0 && input[idx].first > input[idx + 1].first)
			main.push_back(input[idx]);
		else if (idx % 2 == 0 && input[idx].first <= input[idx + 1].first)
			sub.push_back(input[idx]);
		else if (idx % 2 == 1 && input[idx].first > input[idx - 1].first)
			main.push_back(input[idx]);
		else if (idx % 2 == 1 && input[idx].first <= input[idx - 1].first)
			sub.push_back(input[idx]);
	}
	if (main.size() <= 1)
	{
		//std::cout<<sub[0].first<<std::endl;
		if (sub.size() > 0)
			main.insert(main.begin(), sub[0]);
		if (sub.size() > 1)
			main.insert(std::upper_bound(main.begin(), main.end(), sub[1].first, cmp), sub[1]);
		return (main);
	}
	check = recur(main);
	ret = check;
	//std::cout<<std::endl;
	//std::cout<<"sub : "<<sub.size()<<std::endl;
	for (int count = 1; count <= static_cast<int>(main.size()); count++)
	{
		//짝수일 때 자살함 -> 이제 그냥 자살
		int find = 0;
		int idx;

		if (count < std::pow(2, yacop))
		{
			idx = std::pow(2, yacop) - offset - 1;
			if (idx >= static_cast<int>(main.size()))
				idx = main.size() - offset;
		}
		else
		{
			yacop += 1;
			offset = 1;
			idx = std::pow(2, yacop) - offset - 1; // 야콥스탈 수 따라서 하나씩 내려가면 됨
			if (idx >= static_cast<int>(main.size()))
				idx = main.size() - offset;
		}
		//std::cout<<"idx : "<<idx<<std::endl;
		for (int i = 0; i < static_cast<int>(sub.size()); i++)
		{
			if (i == static_cast<int>(main.size()) || (check[idx].first == main[i].first && check[idx].second == main[i].second))
			{
				find = i;
				break;
			}
		}
		ret.insert(upper_bound(ret.begin(), ret.end(), sub[find].first, cmp), sub[find]);
		offset++;
	}
	if (main.size() < sub.size())
		ret.insert(upper_bound(ret.begin(), ret.end(), sub[sub.size() - 1].first, cmp), sub[sub.size() - 1]);
	return (ret);
}


void	PmergeMe::runDeque()
{

}

std::vector<std::pair<int, int> > PmergeMe::getContainer_v() const
{
	return (container_v);
}