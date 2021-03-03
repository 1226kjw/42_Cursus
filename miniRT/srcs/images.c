/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:31 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 17:07:04 by jinukim          ###   ########.fr       */
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

void	make_img(t_data *mlx, t_scene *sn)
{
	t_list	*cam;
	int		i;
	t_arg	*args;

	if (!(args = (t_arg*)ft_calloc(g_y, sizeof(t_arg))))
		errmsg(sn, "malloc");
	cam = sn->cams;
	i = 0;
	while (cam)
	{
		args_set(mlx, sn, (t_cam*)cam->obj, args);
		multithreading(args);
		cam = cam->next;
	}
	free(args);
}
