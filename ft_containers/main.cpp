#include <iostream>
#include <vector>
#include "vector.hpp"

using std::cout;
using std::endl;

int main()
{
	ft::vector<int> a(20);
	for (size_t i = 0; i < a.size(); ++i)
		a[i] = i;
	ft::vector<int> b(a.rbegin(), a.rend());

	for (size_t i = 0; i < b.size(); ++i)
		cout << b[i] << ' ';
	cout << endl;
	size_t c = b.insert(b.begin() + 1, a.begin() + 3, a.begin() + 10) - b.begin();
	//b.reserve(25);
	for (size_t i = 0; i < b.size(); ++i)
		cout << b[i] << ' ';
	cout << endl;
	ft::vector<int>::iterator t = b.erase(b.begin(), b.begin()+5);
	//b.clear();
	for (size_t i = 0; i < b.size(); ++i)
		cout << b[i] << ' ';
	cout << endl;
	cout << t-b.begin() << endl;

	ft::vector<int> d(3,2);
	ft::vector<int> e(4,1);
	swap(d,e);
	cout << (d <= e) << endl;
	return 0;
}
