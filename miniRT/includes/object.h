/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:31:25 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/20 22:52:45 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "minirt.h"

t_sq	*new_sq(t_v3 o, t_v3 n[2], double d, int color);
t_tr	*new_tr(t_v3 a, t_v3 b, t_v3 c, int color);
t_ci	*new_ci(t_v3 o, t_v3 n, double r, int color);
double	i_sp(t_ray ray, void *obj);
double	i_pl(t_ray ray, void *obj);
double	i_sq(t_ray ray, void *obj);
double	i_cy(t_ray ray, void *obj);
double	i_tr(t_ray ray, void *obj);
double	i_ci(t_ray ray, void *obj);
double	i_co(t_ray ray, void *obj);
int		c_sp(t_hit hit);
int		c_pl(t_hit hit);
int		c_sq(t_hit hit);
int		c_cy(t_hit hit);
int		c_tr(t_hit hit);
int		c_ci(t_hit hit);
int		c_co(t_hit hit);
t_v3	n_sp(t_hit hit);
t_v3	n_pl(t_hit hit);
t_v3	n_sq(t_hit hit);
t_v3	n_cy(t_hit hit);
t_v3	n_tr(t_hit hit);
t_v3	n_ci(t_hit hit);
t_v3	n_co(t_hit hit);
void	obj_hub(t_data *mlx, t_scene *sn, int keycode);
void	obj_next(t_scene *sn);
void	obj_bef(t_scene *sn);
void	obj_left(t_data *mlx, t_scene *sn, void *obj);
void	obj_backward(t_data *mlx, t_scene *sn, void *obj);
void	obj_right(t_data *mlx, t_scene *sn, void *obj);
void	obj_down(t_data *mlx, t_scene *sn, void *obj);
void	obj_forward(t_data *mlx, t_scene *sn, void *obj);
void	obj_up(t_data *mlx, t_scene *sn, void *obj);
void	obj_rotx(t_data *mlx, t_scene *sn, void *obj);
void	obj_roty(t_data *mlx, t_scene *sn, void *obj);
void	obj_rotz(t_data *mlx, t_scene *sn, void *obj);

#endif
