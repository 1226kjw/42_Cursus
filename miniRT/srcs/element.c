/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:36 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 20:53:10 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*newcam(t_v3 o, t_v3 d, int fov)
{
	t_cam	*nc;

	if (!(nc = (t_cam*)ft_calloc(1, sizeof(t_cam))))
		errmsg(0, "malloc");
	nc->o = o;
	nc->d = d;
	nc->fov = fov;
	nc->hor = vnorm(d);
	nc->ver = vunit(vcross(d, nc->hor));
	nc->hor = vmul(nc->hor, 2 * vabs(d) * tan(M_PI * fov / 360.0));
	nc->ver = vmul(nc->ver, vabs(nc->hor) * (double)g_y / (double)g_x);
	nc->hl = vsub(d, vadd(vmul(nc->hor, 0.5), vmul(nc->ver, 0.5)));
	return (nc);
}

void	cam_renew(t_data *mlx, t_scene *sn, t_cam *c)
{
	t_arg	*args;

	mlx_clear_window(mlx->mlx, mlx->win);
	if (!(args = (t_arg*)ft_calloc(g_y, sizeof(t_arg))))
		errmsg(sn, "maloc");
	args_set(mlx, mlx->sn, c, args);
	multithreading(args);
	free(args);
	mlx_put_image_to_window(mlx->mlx, mlx->win, c->img, 0, 0);
}

t_light	*newlight(t_v3 o, double inten, int color)
{
	t_light	*nl;

	if (!(nl = (t_light*)ft_calloc(1, sizeof(t_light))))
		errmsg(0, "malloc");
	nl->o = o;
	nl->inten = inten;
	nl->color = color;
	return (nl);
}
