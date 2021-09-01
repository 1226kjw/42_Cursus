#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

using std::cout;
using std::endl;

bool bsp(const Point a, const Point b, const Point c, const Point p);

int main()
{
	Point a(0,0);
	Point b(1,0);
	Point c(0,1);
	Point d(0.5,0.5);
	Point e(-0.5,0.45);
	Point f(0.1,0.1);
	Point g(1.5,0.45);
	cout << bsp(a,b,c,d) << endl;
	cout << bsp(a,b,c,e) << endl;
	cout << bsp(a,b,c,f) << endl;
	cout << bsp(a,b,c,g) << endl;

}
