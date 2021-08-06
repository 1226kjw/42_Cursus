#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
	Phonebook phonebook;
	while (1)
	{
		std::cout << "Choose One : [EXIT, ADD, SEARCH]" << std::endl;
		std::string input;
		do
		{
			clearerr(stdin);
			std::cin.clear();
			std::getline(std::cin, input);
		} while (std::cin.eof());	
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search();
	}
}
