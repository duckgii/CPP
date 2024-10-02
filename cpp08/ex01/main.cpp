#include <ctime>
#include <iostream>
#include "Span.hpp"
#include <vector>

int main()
{
	srand(time(0));
	std::vector<int>	RandNum;
	std::vector<int>	testNum;
	Span num1(50000);
	Span num2(2);

	for (int i = 0; i < 50000; i++)
	{
		RandNum.push_back(rand() % 100000000);
	}
	try
	{
		num1.addManyNumber(RandNum);
		std::cout<<num1.shortestSpan()<<std::endl;
		std::cout<<num1.longestSpan()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 1; i < 11; i++)
	{
		testNum.push_back(i);
	}
	try
	{
		num2.addManyNumber(testNum);
		std::cout<<num2.shortestSpan()<<std::endl;
		std::cout<<num2.longestSpan()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}