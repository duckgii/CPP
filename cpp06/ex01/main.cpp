#include "Serializer.hpp"
#include <iostream>

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