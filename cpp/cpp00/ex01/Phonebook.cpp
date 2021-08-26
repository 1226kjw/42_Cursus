#include "Phonebook.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::setw;
using std::string;

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
	cout << endl;
	string	str[5] = {"", "", "", "", ""};
	for (int i = 0; i < 5; i++)
	{
		while (str[i] == "")
		{
			cout << str_const[i] << " : ";
			getline(cin, str[i]);
			if (cin.eof())
				exit(0);
		}
	}
	Contact	c(str);
	contact[idx++] = c;
	if (idx == 8)
		idx = 0;
	if (total < 8)
		total++;
	cout << endl;
}

void	Phonebook::search()
{
	cout << endl;
	if (total == 0)
	{
		cout << "Phonebook is empty!" << endl << endl;
		return ;
	}
	print();
	int	i = -1;
	while (1)
	{
		cout << endl << "Input Index of Contact : ";
		cin >> i;
		if (cin.eof())
			exit(0);
		if (!cin.fail())
			break ;
		cin.clear();
		cin.ignore(LLONG_MAX, '\n');
		cout << "Idx must be integer" << endl;
	}
	if (0 <= i && i < total)
	{
		cout << endl;
		for (int j = 0; j < 5; j++)
		{
			string data = contact[i].get_info(j);
			cout << setw(15) << str_const[j] << " : " << data << endl;
		}
	}
	else
		cout << "Nothing in idx " << i << endl;
	cout << endl;
	cin.ignore(LLONG_MAX, '\n');
}

void	Phonebook::print(void)
{
	cout << setw(10) << "Index" << '|';
	cout << setw(10) << "First Name" << '|';
    cout << setw(10) << "Last Name" << '|';
    cout << setw(10) << "Nickname" << endl;
	for (int i = 0; i < total; i++)
		contact[i].print(i);
}
