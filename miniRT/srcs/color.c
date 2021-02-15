#include "minirt.h"

int		cred(int a)
{
	return ((a >> 16) & 0xff);
}

int		cgreen(int a)
{
	return ((a >> 8) & 0xff);
}

int		cblue(int a)
{
	return (a & 0xff);
}

int		cset(int r, int b, int c)
{
	int		color;

	if (r > 255)
		r = 255;
	if (b > 255)
		b = 255;
	if (c > 255)
		c = 255;
	color = r << 16;
	color |= b << 8;
	color |= c;
	return (color);
}

int		cadd(int a, int b)
{
	int		c[3];

	c[0] = cred(a) + cred(b);
	c[1] = cgreen(a) + cgreed(b);
	c[2] = cblue(a) + cblue(b);
	return (cset(c[0], c[1], c[2]));
}
int		cmul(int a, double i)
{
	int		c[3];
	
	if (i <= 0.0)
		return (0);
	c[0] = (int)(cred(a) * i);
	c[1] = (int)(cgreen(a) * i);
	c[2] = (int)(cblue(a) * i);
	return (cset(c[0], c[1], c[2]));
}

int		ccom(int a, int b)
{
	int		c[3];

	c[0] = cred(a) * cred(b) / 255;
	c[1] = cgreen(a) * cgreen(b) / 255;
	c[2] = cblue(a) * cblue(b) / 255;
	return (cset(c[0], c[1], c[2]));
}
