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

void    Contact::print(void)
{
    std::string *str = this->get_info();
    for (int i = 0; i < 5; i++)
        if (str[i].length() > 10)
            str[i] = str[i].substr(0, 9) + ".";
    for (int i = 0; i < 5; i++)
        std::cout << std::setw(10) << str[i] << (i == 4 ? "\n" : "|");
    // std::cout << std::setw(10) << last_name << '|';
    // std::cout << std::setw(10) << nickname << '|';
    // std::cout << std::setw(10) << phone_number << '|';
    // std::cout << std::setw(10) << darkest_secret << std::endl;
    delete[] str;
}
