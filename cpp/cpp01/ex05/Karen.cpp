#include "Karen.hpp"

using std::cout;
using std::endl;
using std::string;

Karen::Karen()
{
	f[0] = &Karen::def;
	f[1] = &Karen::debug;
	f[2] = &Karen::info;
	f[3] = &Karen::warning;
	f[4] = &Karen::error;
}

void Karen::def(void)
{
	cout << "[ UNKNOWN ]" << endl << "invalid input" << endl;
}
void Karen::debug(void)
{
	cout << "[ DEBUG ]" << endl << "I love to get extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << endl;
}
void Karen::info(void)
{
	cout << "[ INFO ]" << endl << "I cannot believe adding extra bacon cost more money. \
You don’t put enough! If you did I would not have to ask for it!" << endl;
}
void Karen::warning(void)
{
	cout << "[ WARNING ]" << endl << "I think I deserve to have some extra bacon for free. \
I’ve been coming here for years and you just started working here last month." << endl;
}
void Karen::error(void)
{
	cout << "[ ERROR ]" << endl <<
		"This is unacceptable, I want to speak to the manager now." << endl;
}

void Karen::complain(string level)
{
	string input = "      DEBUG  INFO   WARNINGERROR  ";
	(this->*f[(input.find(level) + 1) / 7])();
	cout << endl;
}
