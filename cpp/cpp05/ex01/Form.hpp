#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;

class Form
{
private:
	const string name;
	bool is_signed;
	const int sign_grade;
	const int exec_grade;
public:
	Form(string name, int s_grade, int e_grade);
	Form(const Form& a);
	virtual ~Form();
	Form& operator= (const Form& a);

	string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat& a);
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream& out, const Form& a);

#endif
