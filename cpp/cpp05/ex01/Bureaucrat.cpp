#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& a) : name(a.name), grade(a.grade) {}
Bureaucrat::Bureaucrat(string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat& Bureaucrat::operator= (const Bureaucrat& a)
{
	name = a.name;
	grade = a.grade;
	return *this;
}

string Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incGrade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decGrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::signForm(Form& f) const
{
	try {
		f.beSigned(*this);
		cout << name << " signs " << f.getName() << endl;
	} catch (std::exception& e) {
		cout << name << " cannot sign " << f.getName() << " because " << e.what() << endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<< (std::ostream& out, const Bureaucrat& a)
{
	out << a.getName() << ", bureaucrat grade: " << a.getGrade();
	return out;
}
