#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

int main(int argc, char **argv)
{
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
		{
			string str(argv[i]);
			for (int j = 0; str[j]; j++)
				if (str[j] >= 'a' && str[j] <= 'z')
					str[j] += 'A' - 'a';
			cout << str;
		}
	cout << endl;
}
