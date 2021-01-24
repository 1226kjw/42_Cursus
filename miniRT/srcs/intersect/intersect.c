#include "minirt.h"

double		ray_pos_dis(t_ray u, t_vec a)
{
	return (vec_abs(vec_cross(vec_sub(a, u.pos), vec_unit(u.dir))));
}
