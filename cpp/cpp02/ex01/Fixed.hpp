#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int		fixed;
	static const int	frac_bit;
public:
	Fixed();
	Fixed(const Fixed &a);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	int		toInt(void) const;
	float	toFloat(void) const;

	Fixed& operator= (const Fixed &a);
};

std::ostream& operator<< (std::ostream& out, const Fixed &a);

#endif
