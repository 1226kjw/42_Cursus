#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("jinukim", 5);
	Form f1("something1", 1, 1);
	Form f2("something2", 5, 5);
	Form f3("something3", 11, 11);
	a.signForm(f1);
	a.signForm(f2);
	a.signForm(f3);
}
