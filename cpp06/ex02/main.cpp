#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include "func.hpp"

int main()
{
	Base base;
	Base *base1;
	Base *base2;
	Base *base3;
	
	srand(time(0));
	base1 = generate();
	base2 = generate();
	base3 = generate();

	identify(base1);
	identify(base2);
	identify(base3);

	identify(*base1);
	identify(*base2);
	identify(*base3);

	delete base1;
	delete base2;
	delete base3;
}