#include "Contact.hpp"

using std::cout;
using std::string;
using std::setw;

Contact::Contact() {}
Contact::Contact(string str[])
{
	first_name = str[0];
	last_name = str[1];
	nickname = str[2];
	phone_number = str[3];
	darkest_secret = str[4];
}
Contact::~Contact() {}

string	Contact::get_info(int i)
{
	switch (i)
	{
	case 0:
		return first_name;
	case 1:
		return last_name;
	case 2:
		return nickname;
	case 3:
		return phone_number;
	case 4:
		return darkest_secret;
	default:
		return "";
	}
}

void    Contact::print(int index)
{
	cout << setw(10) << index << "|";
	for (int i = 0; i < 3; i++)
	{
		string str = get_info(i);
		if (str.length() > 10)
			str = str.substr(0, 9) + ".";
		cout << setw(10) << str << (i == 2 ? "\n" : "|");
	}
}
