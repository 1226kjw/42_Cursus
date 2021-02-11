#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

typedef struct	s_v3
{
	double	x;
	double	y;
	double	z;
}				t_v3;

typedef struct	s_ray
{
	t_v3	o;
	t_v3	d;
}				t_ray;

t_v3			vset(double x, double y, double z);
t_v3			vadd(t_v3 a, t_v3 b);
t_v3			vsub(t_v3 a, t_v3 b);
t_v3			vmul(t_v3 a, double c);
double			vinner(t_v3 a, t_v3 b);
double			vabs(t_v3 a);
t_v3			vcross(t_v3 a, t_v3 b);
t_v3			vunit(t_v3 a);
t_v3			vnorm(t_v3 a);
int				viseq(t_v3, t_v3 b);

#endif
