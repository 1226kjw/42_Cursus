#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class Bureaucrat
{
private:
	string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& a);
	Bureaucrat(string name, int grade);
	virtual ~Bureaucrat();
	Bureaucrat& operator= (const Bureaucrat& a);
	string getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();

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

std::ostream& operator<< (std::ostream& out, const Bureaucrat& a);

#endif
