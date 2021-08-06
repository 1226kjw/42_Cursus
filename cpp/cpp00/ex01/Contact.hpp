#ifndef CONTACT_HPP
# define CONTACT_HPP
 
# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact();
	Contact(std::string str[]);
	~Contact();
	std::string	*get_info(void);
	void	print(void);
};

#endif
