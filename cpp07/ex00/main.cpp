#include "whatever.hpp"
#include <string>

int main()
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
	//int a = 3;
	//int b = 4;
	//int c = 4;

	//std::string s1 = "abc";
	//std::string s2 = "def";
	//std::string s3 = "def";

	//swap(a, b);
	//swap(s1, s2);
	//std::cout<<"a : "<<a<<std::endl;
	//std::cout<<"b : "<<b<<std::endl;
	//std::cout<<"s1 : "<<s1<<std::endl;
	//std::cout<<"s2 : "<<s2<<std::endl;


	//std::cout<<"min : "<<::min(a, b)<<std::endl;
	//std::cout<<"min : "<<::min(a, c)<<std::endl;
	//std::cout<<"max : "<<::max(a, b)<<std::endl;
	//std::cout<<"max : "<<::max(a, c)<<std::endl;

	//std::cout<<"min : "<<::min(s1, s2)<<std::endl; //algorithm 헤더에 min max가 있는데 거기에 const가 붙어있어서 컴파일러가 s1변수를 가져가야 하는지, 리터럴을 가져가야하는지 모호성이 발생해서 에러가 남
	//std::cout<<"max : "<<::max(s1, s2)<<std::endl; //::은 현재 선언되어 있는 네임스페이스에서 함수를 가져오겠다는 의미라서 내가 선언한 함수를 불러온다.
	//return (0);
}