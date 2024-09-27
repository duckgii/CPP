#include "Serializer.hpp"
#include <iostream>

//reinterpret_cast는 임의의 포인터 타입끼리 변환을 허용해주는 캐스팅이다.

int main()
{
	Data *data = new Data();
	uintptr_t	serial;

	data->num = 0;
	std::cout<<"before num : "<<data->num<<std::endl;
	serial = Serializer::serialize(data);
	data = Serializer::deserialize(serial);
	std::cout<<"after num : "<<data->num<<std::endl;
	delete data;
}