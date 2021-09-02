#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int		fixed;
	static const int	frac_bit;
public:
	Fixed();
	Fixed(Fixed &a);
	~Fixed();
	Fixed& operator= (Fixed &a);
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

#endif
