/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:31 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 22:17:45 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_pixel_put(t_cam *cam, int x, int y, int color)
{
	char	*p;
	int		i;

	p = cam->addr;
	i = y * cam->lsize + x * cam->bpp / 8;
	p[i++] = color;
	p[i++] = color >> 8;
	p[i] = color >> 16;
}

void	make_img(t_data *mlx, t_scene *sn, t_arg *args)
{
	t_list	*cam;
	int		i;

	cam = sn->cams;
	i = 0;
	while (cam)
	{
		printf("cam no : %d\n", i++);
		args_set(mlx, sn, (t_cam*)cam->obj, args);
		printf("argset done\n");
		multithreading(args);
		cam = cam->next;
	}
}
