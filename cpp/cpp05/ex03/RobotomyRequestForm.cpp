#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(string target) : Form("RobotomyRequestForm", 72, 45), target(target) { srand(time(0) & reinterpret_cast<unsigned long>(this)); }
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a) : Form("RobotomyRequestForm", 72, 45), target(a.target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& a)
{
	target = a.target;
	return *this;
}

void RobotomyRequestForm::_execute() const
{
	cout << "DDDDDDRRRRRRRRIILLLLLLLLLLINGGGGG" << endl;
	if (rand() & 1)
		cout << target << " has been robotomized successfully" << endl;
	else
		cout << target << " robotomizing fails" << endl;
}
