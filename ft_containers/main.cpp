#include <iostream>
#include <vector>
#include "vector.hpp"

using std::cout;
using std::endl;

int main()
{
	ft::vector<int> a(3, 10);
	*(a._start+1) = 13;
	*(a._start+2) = 15;
	const ft::vector<int>::iterator itr = a.begin();
	ft::vector<int>::iterator ii(itr);
	for (ft::vector<int>::iterator i = a.begin(); i != a.end(); i++)
		cout << *i << endl;
	return 0;
}
