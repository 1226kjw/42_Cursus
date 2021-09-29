#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

using std::string;
using std::cout;
using std::endl;

class Intern
{
private:
	Form* (*make[4])(string s);
	static Form* makedef(string s);
	static Form* makepre(string s);
	static Form* makeshr(string s);
	static Form* makerob(string s);
public:
	Intern();
	Intern(const Intern& a);
	~Intern();
	Intern& operator= (const Intern& a);
	Form* makeForm(string type, string target);
};

#endif
