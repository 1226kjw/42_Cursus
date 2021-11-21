#include <iostream>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"
#include <map>
using std::cout;
using std::endl;

int main()
{
	ft::set<int> a;
	for (int i = 0; i < 11; ++i)
		a.insert(i*i);
	for (ft::set<int>::iterator itr = a.begin(); itr != a.end(); ++itr)
		cout << *itr << endl;
	cout << a.size() << endl;
	return 0;
}
