#include "Point.hpp"
#include <cmath>

bool isSameSide(const Point a, const Point b, const Point p1, const Point p2)
{
	Point v = b - a;
	Point v1 = p1 - a;
	Point v2 = p2 - a; 
	float o1 = v * v1,o2 = v * v2;
	if (o1 * o2 > 0)
		return true;
	return false;
}

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
	if (!isSameSide(a,b,c,p))
		return false;
	if (!isSameSide(b,c,a,p))
		return false;
	if (!isSameSide(c,a,b,p))
		return false;
	return true;
}
