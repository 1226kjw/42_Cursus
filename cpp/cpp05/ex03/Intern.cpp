#include "Intern.hpp"

Form* Intern::makedef(string s) { cout << "Unknown type: " << s << endl; return 0; }
Form* Intern::makeshr(string s) { cout << "Intern create ShrubberyCreationForm" << endl; return new ShrubberyCreationForm(s); }
Form* Intern::makerob(string s) { cout << "Intern create RobotomyRequestForm" << endl; return new RobotomyRequestForm(s); }
Form* Intern::makepre(string s) { cout << "Intern create PresidentialPardonForm" << endl; return new PresidentialPardonForm(s); }

Intern::Intern()
{
	make[0] = makedef;
	make[1] = makeshr;
	make[2] = makerob;
	make[3] = makepre;
}
Intern::Intern(const Intern&) {}
Intern::~Intern() {}
Intern& Intern::operator= (const Intern&) { return *this; }

Form* Intern::makeForm(string type, string target)
{
	string pool = "                   shrubbery creation robotomy request   presidential pardon";
	return make[(pool.find(type) + 1) / 19](target);
}
