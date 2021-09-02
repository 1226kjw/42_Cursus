#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const Point &p) : x(p.x), y(p.y) {}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}
Point::~Point() {}

Fixed Point::getx() const
{
	return x;
}
Fixed Point::gety() const
{
	return y;
}

Point& Point::operator=(const Point& a)
{
	*const_cast<Fixed*>(&x) = a.getx();
	*const_cast<Fixed*>(&y) = a.gety();
	return *this;
}

Point Point::operator-(const Point& a) const
{
	return (Point(x-a.getx(), y-a.gety()));
}
float Point::operator*(const Point& a) const
{
	return (x*a.gety() - y*a.getx()).toFloat();
}


std::ostream& operator<< (std::ostream& out, const Point &a)
{
	out << '(' << a.getx().toFloat() << ", " << a.gety().toFloat() << ')';
	return out;
}
