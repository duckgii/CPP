#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include "func.hpp"

//dynamic cast는 부모클래스의 포인터로 자식클래스의 종류를 런타임에 검사해서 조금 더 안전하게 변환할 수 있는 캐스팅이지만 느려서 잘 쓰지 않는다.

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