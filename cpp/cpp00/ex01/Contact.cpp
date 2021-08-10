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

std::string	*Contact::get_info(void)
{
	std::string *str = new std::string[5];
	str[0] = first_name;
	str[1] = last_name;
	str[2] = nickname;
	str[3] = phone_number;
	str[4] = darkest_secret;
	return (str);
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
