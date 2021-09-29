#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>

# include "Form.hpp"

using std::string;
using std::cout;
using std::endl;

class PresidentialPardonForm : public Form
{
private:
	string target;
	void _execute() const;
public:
	PresidentialPardonForm(string target);
	PresidentialPardonForm(const PresidentialPardonForm& a);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator= (const PresidentialPardonForm& a);
};

#endif
