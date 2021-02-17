/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:59 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/16 13:53:01 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*g_type[] = {"empty", "sphere", "plane", "square", "cylinder",
	"triangle", "cube", "pyramid"};

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
	ray.d = vadd(ray.d, vadd(vmul(delta, 0.5),
				vmul(args->cam->ver, 1.0 / g_y * 2)));
	while (i[0] < g_x)
	{
		hit = calc_pixel(ray, args);
//		printf("%d %d:%s, %06x\n", i[0], i[1], g_type[hit.type + 1], hit.fcol);
		my_pixel_put(args->cam, i[0], i[1], hit.fcol);
		i[0]++;
		ray.d = vadd(ray.d, delta);
	}
	return (NULL);
}

void	multithreading(t_arg *args)
{
	int			i;
	pthread_t	*threads;

	i = -1;
	threads = (pthread_t*)ft_calloc(g_y, sizeof(pthread_t));
	while (++i < g_y)
		if (pthread_create(&threads[i], NULL, make_line_thread, &args[i]))
			errmsg(0, "pthread create error");
	i = -1;
	while (++i < g_y)
		if (pthread_join(threads[i], 0))
			errmsg(0, "pthread join error");
}
