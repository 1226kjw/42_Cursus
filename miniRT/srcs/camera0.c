/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:32:47 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 20:52:43 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_up(t_data *mlx, t_scene *sn)
{
	t_cam	*c;

	c = (t_cam*)mlx->sn->basecam->obj;
	c->o = vadd(c->o, vmul(c->ver, -20.0 / g_y));
	cam_renew(mlx, sn, c);
}

void	cam_down(t_data *mlx, t_scene *sn)
{
	t_cam	*c;

	c = (t_cam*)mlx->sn->basecam->obj;
	c->o = vadd(c->o, vmul(c->ver, 20.0 / g_y));
	cam_renew(mlx, sn, c);
}

void	cam_left(t_data *mlx, t_scene *sn)
{
	t_cam	*c;

	c = (t_cam*)mlx->sn->basecam->obj;
	c->o = vadd(c->o, vmul(c->hor, -20.0 / g_x));
	cam_renew(mlx, sn, c);
}

void	cam_right(t_data *mlx, t_scene *sn)
{
	t_cam	*c;

	c = (t_cam*)mlx->sn->basecam->obj;
	c->o = vadd(c->o, vmul(c->hor, 20.0 / g_x));
	cam_renew(mlx, sn, c);
}
