#include "Phonebook.hpp"
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	Phonebook phonebook;
	while (1)
	{
		cout << "Choose One : [EXIT, ADD, SEARCH]" << endl;
		string input;
		getline(cin, input);
		if (cin.eof() || input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
	}
}
