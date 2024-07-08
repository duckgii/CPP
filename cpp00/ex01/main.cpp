#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout<<"Input command [1. ADD, 2. SEARCH, 3. EXIT] : ";
		std::cin>>input;
		if (input == "ADD" || input == "1")
			phonebook.AddContact();
		else if (input == "SEARCH" || input == "2")
		{
			phonebook.DisplayContact();
			phonebook.SearchIndex();
		}
		else if (input == "EXIT" || input == "3")
			break;
		else
			std::cout<<"Input command is wrong!!"<<std::endl;
		std::cin.clear();
		clearerr(stdin);
	}
}