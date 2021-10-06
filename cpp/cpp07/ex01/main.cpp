#include "iter.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::endl;

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const  & x ) { std::cout << x << std::endl; return; }

int main()
{
	int a[5] = {1,2,3,4,5};
	float b[3] = {2.2, 3.2, 4.2};
	string c[2] = {"111111", "222"};
	
	iter(a, 5, print);
	cout << endl;
	iter(b, 3, print);
	cout << endl;
	iter(c, 2, print);
	cout << endl;
	cout << "------------------" << endl;
	int tab[] = {0,1,2,3,4};
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);

}
