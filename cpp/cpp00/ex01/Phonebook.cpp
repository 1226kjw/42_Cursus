#include "Phonebook.hpp"

Phonebook::Phonebook() : total(0), idx(0)
{
	str_const[0] = "First Name";
	str_const[1] = "Last Name";
	str_const[2] = "NickName";
	str_const[3] = "Phone Number";
	str_const[4] = "Darkest Secret";
}
Phonebook::~Phonebook() {}

void	Phonebook::add()
{
	std::cout << std::endl;
	std::string	str[5];
	for (int i = 0; i < 5; i++)
	{
		std::cout << str_const[i] << " : ";
		do
		{
			clearerr(stdin);
			std::cin.clear();
			std::getline(std::cin, str[i]);
		} while (std::cin.eof());	
	}
	Contact	c(str);
	contact[idx++] = c;
	if (idx == 8)
		idx = 0;
	if (total < 8)
		total++;
	std::cout << std::endl;
}

void	Phonebook::search()
{
	if (total == 0)
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl << std::endl;
		return ;
	}
	std::cout << std::endl;
	print();
	std::cout << std::endl << "Input Index of Contact : ";
	int	i;
	std::cin >> i;
	if (std::cin.fail())
	{
		std::cout << "Idx must be integer" << std::endl;
		std::cin.clear();
	}
	else if (0 <= i && i < total)
	{
		std::cout << std::endl;
		std::string *info = contact[i].get_info();
		for (int i = 0; i < 5; i++)
			std::cout << std::setw(15) << str_const[i] << " : " << info[i] << std::endl;
		delete[] info;
	}
	else
		std::cout << "Nothing in idx " << i << std::endl;
	std::cout << std::endl;
	std::cin.ignore(LLONG_MAX, '\n');
}

void	Phonebook::print(void)
{
	std::cout << std::setw(10) << "Index" << '|';
	std::cout << std::setw(10) << "First Name" << '|';
    std::cout << std::setw(10) << "Last Name" << '|';
    std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < total; i++)
		contact[i].print(i);
}
