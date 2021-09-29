#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("jinukim", 1);
	ShrubberyCreationForm s("here");
	RobotomyRequestForm r("dog");
	PresidentialPardonForm p("who");
	a.signForm(s);
	a.executeForm(s);
	a.signForm(r);
	a.executeForm(r);
	a.signForm(p);
	a.executeForm(p);
}
