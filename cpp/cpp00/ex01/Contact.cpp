#include "Contact.hpp"

Contact::Contact() {}
Contact::Contact(std::string str[])
{
	first_name = str[0];
	last_name = str[1];
	nickname = str[2];
	phone_number = str[3];
	darkest_secret = str[4];
}
Contact::~Contact() {}

std::string	*Contact::get_info(int i)
{
	switch (i)
	{
	case 1:
		return first_name;
	case 2:
		return last_name;
	case 3:
		return nickname;
	case 4:
		return phone_number;
	case 5:
		return darkest_secret;
	default:
		return "";
	}
}

void    Contact::print(int index)
{
	std::string *str = get_info();
	
	std::cout << std::setw(10) << index << "|";
	for (int i = 0; i < 3; i++)
	{
		if (str[i].length() > 10)
			str[i] = str[i].substr(0, 9) + ".";
		std::cout << std::setw(10) << str[i] << (i == 2 ? "\n" : "|");
	}
	delete[] str;
}
