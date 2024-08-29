#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"

//void	check(void)
//{
//	system("leaks a.out");
//}

int main()
{
	//atexit(check);
	Dog		dog1;
	Dog		dog2(dog1);
	Cat		cat1;
	Cat		cat2(cat1);
	WrongAnimal	wrongAnimal1;
	WrongAnimal	wrongAnimal2(wrongAnimal1);
	WrongCat	wrongCat1;
	WrongCat	wrongCat2(wrongCat1);

	std::cout<<"\n\n";
	std::cout<<dog1.getType()<<" "<<std::endl;
	dog1.makeSound();
	std::cout<<cat1.getType()<<" "<<std::endl;
	cat1.makeSound();
	std::cout<<wrongAnimal1.getType()<<" "<<std::endl;
	wrongAnimal1.makeSound();
	std::cout<<wrongCat1.getType()<<" "<<std::endl;
	wrongCat1.makeSound();
	std::cout<<"\n\n";

	return (0);
}