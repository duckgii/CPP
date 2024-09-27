#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		class InvalidIndex : public std::exception // 퍼블릭으로 상속받아야함
		{
			virtual const char* what() const throw()
			{
				return ("Invalid Index!!");
			}
		};
		T	*array;
		unsigned int len;
	public:
		Array() 
		{
			len = 0;
			this->array = new T[0];
		}

		Array(unsigned int n) 
		{
			len = n;
			this->array = new T[n];
		}

		~Array(){delete this->array;}

		Array(Array &copy)
		{
			this->array = new T[copy.getLen()];
			this->len = copy.getLen();
			for (unsigned int i = 0; i < this->len; i++)
			{
				this->array[i] = copy[i];
			}
		}

		Array& operator=(Array &in)
		{
			if (this == &in)
				return (*this);
			delete this->array;
			this->array = new T[in.getLen()];
			this->len = in.getLen();
			for (unsigned int i = 0; i < this->len; i++)
			{
				this->array[i] = in[i];
			}
		}

		T& operator[](unsigned int find) const
		{
			if (find >= len)
				throw Array::InvalidIndex();
			return (this->array[find]);
		}

		T& operator[](unsigned int find)
		{
			if (find >= len)
				throw Array::InvalidIndex();
			return (this->array[find]);
		}
		unsigned int getLen() {return (this->len);}
};

#endif