#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# include "Form.hpp"

using std::string;
using std::cout;
using std::endl;

class Form;

class Bureaucrat
{
private:
	string name;
	int grade;
public:
	Bureaucrat(string name, int grade);
	Bureaucrat(const Bureaucrat& a);
	virtual ~Bureaucrat();
	Bureaucrat& operator= (const Bureaucrat& a);

	string getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();
	void signForm(Form& f) const;
	void executeForm(const Form& f) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw() { return "Grade is too high"; }
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw() { return "Grade is too low"; }
	};
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& a);

#endif
