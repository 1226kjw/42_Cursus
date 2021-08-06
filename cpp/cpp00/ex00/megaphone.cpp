#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			for (int j = 0; str[j]; j++)
				if (str[j] >= 'a' && str[j] <= 'z')
					str[j] += 'A' - 'a';
			std::cout << str;
		}
	std::cout << std::endl;
}
