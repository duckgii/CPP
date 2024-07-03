#include <iostream>

class	Megaphone
{
	public:
		char * upper_str;
		char * UpperCase(char *input)
		{
			int		idx = 0;

			upper_str = new char(std::strlen(input) + 1);
			for(idx = 0; input[idx] != '\0'; idx++)
			{
				upper_str[idx] = std::toupper(input[idx]);
			}
			upper_str[idx] = '\0';
			return (upper_str);
		}
		void Noise()
		{
			std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		}
};

int main(int ac, char *av[])
{
	Megaphone	obj;

	if (av[1] == NULL)
	{
		obj.Noise();
		return (0);
	}
	else
	{
		for (int idx = 1; av[idx] != NULL; idx++)
		{
			std::cout<<obj.UpperCase(av[idx])<<" ";
			delete []obj.upper_str;
		}
		std::cout<<std::endl;
	}
	return (0);
}