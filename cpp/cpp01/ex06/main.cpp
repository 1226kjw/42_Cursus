#include "Karen.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "argc must be 2" << endl;
		return 0;
	}
	Karen a;
	a.complain(argv[1]);
}
