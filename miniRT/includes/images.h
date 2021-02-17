/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:29:37 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/17 23:05:41 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

# include "minirt.h"

void	args_set(t_data *mlx, t_scene *sn, t_cam *cam, t_arg *args);
void	*make_line_thread(void *p);
void	multithreading(t_arg *args);
void	my_pixel_put(t_cam *cam, int x, int y, int color);
void	make_img(t_data *mlx, t_scene *sn, t_arg *args);
t_hit	calc_pixel(t_ray ray, t_arg *args);
t_hit	closest(t_ray ray, t_list *objs);
int		calc_diffuse(t_hit hit, t_light *cur);
int		calc_specular(t_ray ray, t_hit hit, t_light *cur);
void	p_light(t_hit *hit, t_scene *sn);

#endif
