/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:29:28 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 21:19:07 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "minirt.h"

t_cam	*newcam(t_v3 o, t_v3 d, int fov);
t_light	*newlight(t_v3 o, double inten, int color);
void	cam_renew(t_data *mlx, t_scene *sn, t_cam *c);
void	cam_up(t_data *mlx, t_scene *sn);
void	cam_down(t_data *mlx, t_scene *sn);
void	cam_left(t_data *mlx, t_scene *sn);
void	cam_right(t_data *mlx, t_scene *sn);
void	cam_backward(t_data *mlx, t_scene *sn);
void	cam_forward(t_data *mlx, t_scene *sn);
void	cam_reset(t_data *mlx, t_scene *sn);

#endif
