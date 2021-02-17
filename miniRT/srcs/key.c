/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:03:27 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/17 18:49:21 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_bef(t_data *mlx, t_scene *sn)
{
	if (sn->basecam->bef)
		sn->basecam = sn->basecam->bef;
	else
		sn->basecam = ft_lstlast(sn->cams);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, ((t_cam*)sn->basecam->obj)->img, 0, 0);
}

void	cam_next(t_data *mlx, t_scene *sn)
{
	if (sn->basecam->next)
		sn->basecam = sn->basecam->next;
	else
		sn->basecam = sn->cams;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, ((t_cam*)sn->basecam->obj)->img, 0, 0);
}

int		close_program(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	errmsg(0, 0);
	return (0);
}

int		key_handle(int keycode, t_data *mlx)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		close_program(mlx);
	else if (keycode == LEFT)
		cam_bef(mlx, mlx->sn);
	else if (keycode == RIGHT)
		cam_next(mlx, mlx->sn);
	return (0);
}
