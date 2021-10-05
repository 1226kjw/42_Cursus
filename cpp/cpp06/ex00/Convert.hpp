#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cctype>

using std::string;
using std::cout;
using std::endl;

class Convert
{
private:
	string raw_str;
	int prec;
	char toChar();
	int toInt();
	float toFloat();
	double toDouble();
public:
	Convert(string s);
	Convert(const Convert& a);
	~Convert();
	Convert& operator= (const Convert& a);
	
	void printAll();
};

#endif
