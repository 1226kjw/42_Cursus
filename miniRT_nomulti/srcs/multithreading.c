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
	t_v3		delta;

	args = (t_arg*)p;
	ray.o = args->cam->o;
	i[1] = args->id;
	ray.d = vadd(args->cam->hl, vmul(args->cam->ver, (double)i[1] / g_y));
	i[0] = 0;
	hit.type = -1;
	delta = vmul(args->cam->hor, 1.0 / (double)g_x);
	while (i[0] < g_x)
	{
		printf("%d %d  :  ",i[0],i[1]);
		hit = closest(ray, args->sn->objs);
		printf("%lf %d %06x\n",hit.t, hit.type, hit.color);
/*		if (hit.t >= 0.0)
			add_light(hit);
		if (hit.t >= 0.0)
			add_spec(hit);*/
		my_pixel_put(args->cam, i[0], i[1], hit.color);
		i[0]++;
		ray.d = vadd(ray.d, delta);
	}
	return (NULL);
}

void	multithreading(t_arg *args)
{
	int			i;

	i = -1;
	while (++i < g_y)
	{
		make_line_thread(&args[i]);
	}
}
