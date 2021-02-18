/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:03:27 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 20:50:17 by jinukim          ###   ########.fr       */
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
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}

void	cam_next(t_data *mlx, t_scene *sn)
{
	if (sn->basecam->next)
		sn->basecam = sn->basecam->next;
	else
		sn->basecam = sn->cams;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}

int		close_program(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	errmsg(0, 0);
	return (0);
}

int		button_handle(int button, int x, int y, t_data *mlx)
{
	t_cam	*c;

	if (button == BUT1_KEY)
	{
		c = (t_cam*)mlx->sn->basecam->obj;
		c->d = vunit(vadd(vadd(c->d, vmul(c->hor, x / (double)g_x - 0.5)),
				vmul(c->ver, y / (double)g_y - 0.5)));
		c->hor = vnorm(c->d);
		c->ver = vunit(vcross(c->d, c->hor));
		c->hor = vmul(c->hor, 2 * vabs(c->d) * tan(M_PI * c->fov / 360.0));
		c->ver = vmul(c->ver, vabs(c->hor) * (double)g_y / g_x);
		c->hl = vsub(c->d, vadd(vmul(c->hor, 0.5), vmul(c->ver, 0.5)));
		cam_renew(mlx, mlx->sn, c);
	}
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
	else if (keycode == W_KEY)
		cam_up(mlx, mlx->sn);
	else if (keycode == S_KEY)
		cam_down(mlx, mlx->sn);
	else if (keycode == A_KEY)
		cam_left(mlx, mlx->sn);
	else if (keycode == D_KEY)
		cam_right(mlx, mlx->sn);
	else if (keycode == Q_KEY)
		cam_backward(mlx, mlx->sn);
	else if (keycode == E_KEY)
		cam_forward(mlx, mlx->sn);
	return (0);
}
