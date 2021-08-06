#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
 
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# include <climits>

class Phonebook
{
private:
	int		total;
	int		idx;
	std::string str_const[5];
	Contact	contact[8];
public:
	Phonebook();
	~Phonebook();
	void	add_contact();
	void	search();
	void	print(int i);
	void	print(void);
};

#endif