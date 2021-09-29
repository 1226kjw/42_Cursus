#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>

# include "Form.hpp"

using std::string;
using std::cout;
using std::endl;

class RobotomyRequestForm : public Form
{
private:
	string target;
	void _execute() const;
public:
	RobotomyRequestForm(string target);
	RobotomyRequestForm(const RobotomyRequestForm& a);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator= (const RobotomyRequestForm& a);
};

#endif
