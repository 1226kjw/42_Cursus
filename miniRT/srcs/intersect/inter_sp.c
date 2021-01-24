#include "minirt.h"

int		inter_sp(t_ray u, t_sphere c)
{
	double	d;

	d = ray_pos_dis(u, c.pos);
	if (d == c.r)
		return (1);
	else if (d < c.r)
		return (2);
	else if (d > c.r)
		return (0);
	return (-999);
}
