#include "Form.hpp"

Form::Form(string name, int s_grade, int e_grade) : name(name), is_signed(false), sign_grade(s_grade), exec_grade(e_grade)
{
	if (s_grade > 150 || e_grade > 150)
		throw Form::GradeTooLowException();
	else if (s_grade < 1 || e_grade < 1)
		throw Form::GradeTooHighException();
}
Form::Form(const Form& a) : name(a.name), is_signed(a.is_signed), sign_grade(a.sign_grade), exec_grade(a.exec_grade) {}
Form::~Form() {}
Form& Form::operator= (const Form& a)
{
	is_signed = a.is_signed;
	return *this;
}

string Form::getName() const { return name; }
bool Form::getSigned() const { return is_signed; }
int Form::getSignGrade() const { return sign_grade; }
int Form::getExecGrade() const { return exec_grade; }

void Form::beSigned(const Bureaucrat& a)
{
	if (a.getGrade() <= sign_grade)
		is_signed = true;
	else
		throw Form::GradeTooLowException();
}
void Form::execute(const Bureaucrat& executor) const
{
	if (!is_signed)
		throw Form::NotSignedException();
	else if (exec_grade < executor.getGrade())
		throw Form::GradeTooLowException();
	this->_execute();
}
