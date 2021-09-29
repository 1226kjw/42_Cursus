#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>

# include "Form.hpp"

using std::string;

class ShrubberyCreationForm : public Form
{
private:
	string target;
	void _execute() const;
public:
	ShrubberyCreationForm(string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& a);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& a);
};

#endif
