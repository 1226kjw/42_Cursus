/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:03:27 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/16 20:44:47 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		close_program(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

int		key_handle(int keycode, t_data *mlx)
{
	if (keycode == 53)
		mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}
