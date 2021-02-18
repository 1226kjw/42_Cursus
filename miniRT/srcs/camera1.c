/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:47:08 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 20:49:35 by jinukim          ###   ########.fr       */
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
