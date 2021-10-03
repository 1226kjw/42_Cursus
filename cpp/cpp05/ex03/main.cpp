#include "Bureaucrat.hpp"
#include "Intern.hpp"
int main()
{
	Bureaucrat a("jinukim", 7);
	Intern intern;
	Form* s = intern.makeForm("shrubbery creation", "here");
	Form* r = intern.makeForm("robotomy request", "dog");
	Form* p = intern.makeForm("presidential pardon", "who");
	Form* u = intern.makeForm("uuuuuuuuuuuu", "dog");
	a.signForm(*s);
	a.executeForm(*s);
	a.signForm(*r);
	a.executeForm(*r);
	a.signForm(*p);
	a.executeForm(*p);
	delete s;
	delete r;
	delete p;
	delete u;
}
