#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("jinukim", 1);
	Bureaucrat b("bob", 150);
	cout << a << endl;
	cout << b << endl;
	try {
		a.incGrade();
		cout << a << endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		cout << e.what() << endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
		cout << e.what() << endl;
	}
	try {
		b.decGrade();
		cout << b << endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
		cout << e.what() << endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		cout << e.what() << endl;
	}
	try {
		a.decGrade();
		cout << a << endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		cout << e.what() << endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
		cout << e.what() << endl;
	}
}
