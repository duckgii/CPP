#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>

struct Data
{
	int num;
};

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(Serializer &copy);
		Serializer& operator=(Serializer &in);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif