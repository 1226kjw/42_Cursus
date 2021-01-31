#include "minirt.h"

unsigned int	vec_color(t_vec c)
{
	unsigned int	col;

	col = 0;
	col |= ((unsigned int)(c.x * 255.5)) << 16;
	col |= ((unsigned int)(c.y * 255.5)) << 8;
	col |= ((unsigned int)(c.z * 255.5));
	return (col);
}

void			my_pixel_put(t_scene *sd, int x, int y, unsigned int col)
{
	char			*arg;
	
	arg = sd->cam[sd->nth].img.addr + sd->cam[sd->nth].img.bytes_per_line * y + sd->cam[sd->nth].img.bits_per_pixel * x / 8;
	arg[1] = (col >> 16) & 0xff;
	arg[2] = (col >> 8) & 0xff;
	arg[3] = col & 0xff;
}

int				make_image(t_scene *sd)
{
	int				i;
	int				j;
	t_vec			xvec;
	t_vec			yvec;
	t_ray			r;
	t_ray			k;

	xvec = vec_normal(sd->cam->dir);
	yvec = vec_unit(vec_cross(sd->cam->dir, xvec));
	xvec = vec_mul(xvec, 2 * vec_abs(sd->cam->dir) * tan(M_PI * sd->cam->fov / 2.0 / 180));
	yvec = vec_mul(yvec, vec_abs(xvec) * (double)sd->y / (double)sd->x);
	r.pos = sd->cam->pos;
	r.dir = vec_sub(vec_sub(sd->cam->dir, vec_mul(xvec, 0.5)), vec_mul(yvec, 0.5));
	j = -1;
	while (++j < sd->y)
	{
		i = -1;
		printf("%d\n", j);
		while (++i < sd->x)
		{
			k = r;
			k.dir = vec_add(vec_add(r.dir, vec_mul(xvec, (double)i / sd->x)), vec_mul(yvec, (double)j / sd->y));
			if (inter_sp(k, sd->sphere[0]) > 0)
				my_pixel_put(sd, i, j, vec_color(sd->sphere[0].color));
			else
				my_pixel_put(sd, i, j, C_BG);
		}
	}
	return (0);
}
