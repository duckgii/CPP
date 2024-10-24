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
		container_l.push_back(std::make_pair(std::atoi(num.c_str()), i));
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
	ret = recur_v(container_v);
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

std::vector<std::pair<int, int> > PmergeMe::recur_v(std::vector<std::pair<int, int> > input)
{
	std::vector<std::pair<int, int> > main;
	std::vector<std::pair<int, int> > sub;
	std::vector<std::pair<int, int> > ret;
	std::vector<std::pair<int, int> > check;
	int		yacop = 1;
	int 	pre = -1;
	int 	t = 0;

	for (int idx = 0; idx < static_cast<int>(input.size()); idx++)
	{
		if (idx % 2 == 0 && idx + 1 == static_cast<int>(input.size()))
			sub.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 0 && input[idx].first > input[idx + 1].first)
			main.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 0 && input[idx].first <= input[idx + 1].first)
			sub.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 1 && input[idx].first > input[idx - 1].first)
			main.push_back(std::make_pair(input[idx].first, idx));
		else if (idx % 2 == 1 && input[idx].first <= input[idx - 1].first)
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
	ret = check;
	//std::cout<<"check size : "<<check.size()<<" main size : "<<main.size()<<" sub size : "<<sub.size()<<std::endl;
	for (int i = 0 ;i < static_cast<int>(main.size()); i++)
	{
		//std::cout<<"main.size : "<<main.size()<<" ret[i] : "<<ret[i].second<<" i : "<<i<<std::endl;
		ret[i].second = main[ret[i].second].second;
	}
	int idx = 0;
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
		//std::cout<<check[idx].second<<std::endl;
		ret.insert(upper_bound(ret.begin(), ret.begin() + std::min(static_cast<int>(ret.size()), static_cast<int>(std::pow(2, yacop))), sub[check[idx].second].first, cmp), sub[check[idx].second]);
		//std::cout<<count<<std::endl;
		idx--;
	}
	//std::cout<<"hi"<<std::endl;
	if (main.size() < sub.size())
		ret.insert(upper_bound(ret.begin(), ret.end(), sub[sub.size() - 1].first, cmp), sub[sub.size() - 1]);
	//std::cout<<std::endl<<"return : "<<std::endl;
	//for (int i =0; i < static_cast<int>(ret.size()); i++)
	//{
	//	std::cout<<ret[i].first<<" ";
	//}
	//std::cout<<std::endl;
	//for (int i =0; i < static_cast<int>(ret.size()); i++)
	//{
	//	std::cout<<ret[i].second<<" ";
	//}
	//std::cout<<std::endl;
	return (ret);
}

//std::list<std::pair<int, int> > recur_l(std::list<std::pair<int, int> > input)
//{

//}

void	PmergeMe::runlist()
{
	std::list<std::pair<int, int> > ret;

	//ret = recur_l(container_l);
	//for (int i = 0; i < static_cast<int>(ret.size()); i++)
	//{
	//	std::cout<<ret.front().first<<" ";
	//	ret.pop_front();
	//}
	//std::cout<<"\n";
}

std::vector<std::pair<int, int> > PmergeMe::getContainer_v() const
{
	return (container_v);
}