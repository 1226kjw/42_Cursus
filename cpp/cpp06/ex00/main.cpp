#include <iostream>
#include <string>
#include "Convert.hpp"

using std::string;
using std::endl;
using std::cout;

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		Convert a(argv[i]);
		a.printAll();
	}
}
