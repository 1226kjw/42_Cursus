#include "minirt.h"

void	args_set(t_data *mlx, t_scene *sn, t_cam *cam, t_arg *args)
{
	int			i;

	i = 0;
	while (i < g_y)
	{
		args[i].mlx = mlx;
		args[i].sn = sn;
		args[i].cam = cam;
		args[i].id = i;
		i++;
	}
}

void	*make_line_thread(void *p)
{
	t_arg		*args;
	t_ray		ray;
	int			i[2];
	t_hit		hit;

	args = (t_arg*)p;
	ray.o = args->cam->o;
	i[1] = args->id;
	ray.d = vadd(args->cam->hl, vmul(args->cam->ver, (double)i[1]));
	i[0] = 0;
	hit.type = -1;
	while (i[0] < g_x)
	{
		hit = closest(ray, args->sn->objs);
/*		if (hit.t >= 0.0)
			add_light(hit);
		if (hit.t >= 0.0)
			add_spec(hit);*/
		my_pixel_put(args->cam, i[0], i[1], hit.color);
		i[0]++;
		ray.d = vadd(ray.d, args->cam->hor);
	}
	return (NULL);
}

void	multithreading(t_arg *args)
{
	int			i;

	i = -1;
	while (++i < g_y)
		make_line_thread(&args[i]);
}
