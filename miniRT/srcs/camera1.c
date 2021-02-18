/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:47:08 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 21:25:53 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_backward(t_data *mlx, t_scene *sn)
{
	t_cam	*c;

	c = (t_cam*)mlx->sn->basecam->obj;
	c->o = vadd(c->o, vmul(c->d, -SCALE));
	cam_renew(mlx, sn, c);
}

void	cam_forward(t_data *mlx, t_scene *sn)
{
	t_cam	*c;

	c = (t_cam*)mlx->sn->basecam->obj;
	c->o = vadd(c->o, vmul(c->d, SCALE));
	cam_renew(mlx, sn, c);
}

void	cam_reset(t_data *mlx, t_scene *sn)
{
	t_cam	*c;

	c = (t_cam*)mlx->sn->basecam->obj;
	c->o = c->o_org;
	c->d = c->d_org;
	c->hor = vnorm(c->d);
	c->ver = vunit(vcross(c->d, c->hor));
	c->hor = vmul(c->hor, 2 * vabs(c->d) * tan(M_PI * c->fov / 360.0));
	c->ver = vmul(c->ver, vabs(c->hor) * (double)g_y / g_x);
	c->hl = vsub(c->d, vadd(vmul(c->hor, 0.5), vmul(c->ver, 0.5)));
	cam_renew(mlx, sn, c);
}
