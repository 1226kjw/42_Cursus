#include "minirt.h"

int		make_img(t_data *data, t_scene *sd)
{
	int		i;
	int		j;
	t_vec	xvec;
	t_vec	yvec;
	t_ray	r;
	t_ray	k;

	xvec = vec_normal(sd->cam->v);
	yvec = vec_unit(vec_cross(sd->cam->v, xvec));
	xvec = vec_mul(xvec, 2 * vec_abs(sd->cam->v) * tan(sd->cam->fov / 2.0));
	yvec = vec_mul(yvec, vec_abs(xvec) * (double)sd->y / (double)sd->x);
	r.pos = sd->cam->pos;
	r.dir = vec_sub(vec_sub(sd->cam->v, vec_mul(xvec, 0.5)), vec_mul(yvec, 0.5));
	j = -1;
	while (++j < sd->y)
	{
		i = -1
		while (++i < sd->x)
		{
			k = r;
			k.dir = vec_add(vec_add(r.dir, vec_mul(xvec, (double)i / sd->x)), vec_mul(yvec, (double)j / sd->y));
			if (intersect(r, sd->sphere[0]) > 0)
				mlx_pixel_put(data->mlx, data->mlx_win, i, j, 0x00ff0000);
			else
				mlx_pixel_put(data->mlx, data->mlx_win, i, j, 0x00000000);
		}
	}
	return (0);
}
