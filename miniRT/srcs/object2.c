/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:30:24 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:30:25 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	obj_rotx(t_data *mlx, t_scene *sn, void *obj)
{
	if (sn->baseobj->type == SP)
		return ;
	else if (sn->baseobj->type == PL)
		((t_pl*)obj)->n = vrotx(((t_pl*)obj)->n, ANGLE);
	else if (sn->baseobj->type == SQ)
		((t_sq*)obj)->n = vrotx(((t_sq*)obj)->n, ANGLE);
	else if (sn->baseobj->type == CY)
		((t_cy*)obj)->d = vrotx(((t_cy*)obj)->d, ANGLE);
	else if (sn->baseobj->type == TR)
	{
		((t_tr*)obj)->a = vrotx(((t_tr*)obj)->a, ANGLE);
		((t_tr*)obj)->b = vrotx(((t_tr*)obj)->b, ANGLE);
		((t_tr*)obj)->c = vrotx(((t_tr*)obj)->c, ANGLE);
	}
	else if (sn->baseobj->type == CI)
		((t_ci*)obj)->n = vrotx(((t_ci*)obj)->n, ANGLE);
	else if (sn->baseobj->type == CO)
		((t_co*)obj)->d = vrotx(((t_co*)obj)->d, ANGLE);
	mlx_clear_window(mlx->mlx, mlx->win);
	make_img(mlx, sn);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}

void	obj_roty(t_data *mlx, t_scene *sn, void *obj)
{
	if (sn->baseobj->type == SP)
		return ;
	else if (sn->baseobj->type == PL)
		((t_pl*)obj)->n = vroty(((t_pl*)obj)->n, ANGLE);
	else if (sn->baseobj->type == SQ)
		((t_sq*)obj)->n = vroty(((t_sq*)obj)->n, ANGLE);
	else if (sn->baseobj->type == CY)
		((t_cy*)obj)->d = vroty(((t_cy*)obj)->d, ANGLE);
	else if (sn->baseobj->type == TR)
	{
		((t_tr*)obj)->a = vroty(((t_tr*)obj)->a, ANGLE);
		((t_tr*)obj)->b = vroty(((t_tr*)obj)->b, ANGLE);
		((t_tr*)obj)->c = vroty(((t_tr*)obj)->c, ANGLE);
	}
	else if (sn->baseobj->type == CI)
		((t_ci*)obj)->n = vroty(((t_ci*)obj)->n, ANGLE);
	else if (sn->baseobj->type == CO)
		((t_co*)obj)->d = vroty(((t_co*)obj)->d, ANGLE);
	mlx_clear_window(mlx->mlx, mlx->win);
	make_img(mlx, sn);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}

void	obj_rotz(t_data *mlx, t_scene *sn, void *obj)
{
	if (sn->baseobj->type == SP)
		return ;
	else if (sn->baseobj->type == PL)
		((t_pl*)obj)->n = vrotz(((t_pl*)obj)->n, ANGLE);
	else if (sn->baseobj->type == SQ)
		((t_sq*)obj)->n = vrotz(((t_sq*)obj)->n, ANGLE);
	else if (sn->baseobj->type == CY)
		((t_cy*)obj)->d = vrotz(((t_cy*)obj)->d, ANGLE);
	else if (sn->baseobj->type == TR)
	{
		((t_tr*)obj)->a = vrotz(((t_tr*)obj)->a, ANGLE);
		((t_tr*)obj)->b = vrotz(((t_tr*)obj)->b, ANGLE);
		((t_tr*)obj)->c = vrotz(((t_tr*)obj)->c, ANGLE);
	}
	else if (sn->baseobj->type == CI)
		((t_ci*)obj)->n = vrotz(((t_ci*)obj)->n, ANGLE);
	else if (sn->baseobj->type == CO)
		((t_co*)obj)->d = vrotz(((t_co*)obj)->d, ANGLE);
	mlx_clear_window(mlx->mlx, mlx->win);
	make_img(mlx, sn);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}
