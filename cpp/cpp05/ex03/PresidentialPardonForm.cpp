#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(string target) : Form("PresidentialPardonForm", 25, 5), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& a) : Form("PresidentialPardonForm", 25, 5), target(a.target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& a)
{
	target = a.target;
	return *this;
}

void PresidentialPardonForm::_execute() const
{
	cout << target << " has been pardoned by Zafod Beeblebrox" << endl;
}
