#include "func.hpp"
#include <iostream>

Base* generate(void)
{
	int num = rand();

	if (num % 3 == 0)
		return (new A);
	else if (num % 3 == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout<<"this class is A"<<std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout<<"this class is B"<<std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout<<"this class is C"<<std::endl;
}

void identify(Base& p)
{
	A a;
	B b;
	C c;

	try
	{
		a = dynamic_cast<A&>(p);
		std::cout<<"this class is A"<<std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			b = dynamic_cast<B&>(p);
			std::cout<<"this class is B"<<std::endl;
		}
		catch (const std::exception& e)
		{
			try
			{
				c = dynamic_cast<C&>(p);
				std::cout<<"this class is C"<<std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout<<e.what()<<std::endl;
			}
		}
	}
}