#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Point &p);
	Point(const float x, const float y);
	Point(const Fixed &x, const Fixed &y);
	~Point();

	Fixed getx(void) const;
	Fixed gety(void) const;
	//Point& operator=(const Point &a);
	Point operator-(const Point& a) const;
	float operator*(const Point& a) const;
};

std::ostream& operator<< (std::ostream& out, const Point &a);

#endif
