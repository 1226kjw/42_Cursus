/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:03:27 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/17 17:21:01 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	return (0);
}
