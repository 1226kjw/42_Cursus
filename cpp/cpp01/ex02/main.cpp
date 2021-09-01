#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
	string str = "HI THIS IS BRAIN";
	string *strPTR = &str;
	string &strREF = str;

	cout << "   str: " << &str << endl;
	cout << "strPTR: " << &strPTR << "->" << strPTR << endl;
	cout << "strREF: " << &strREF << endl;
	cout << endl;
	cout << "   str: " << str << endl;
	cout << "strPTR: " << *strPTR << endl;
	cout << "strREF: " << strREF << endl;

}
