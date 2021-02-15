/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:31:25 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:31:30 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "minirt.h"

double	i_sp(t_ray ray, void *obj);
double	i_pl(t_ray ray, void *obj);
double	i_sq(t_ray ray, void *obj);
double	i_cy(t_ray ray, void *obj);
double	i_tr(t_ray ray, void *obj);
int		c_sp(void *obj);
int		c_pl(void *obj);
int		c_sq(void *obj);
int		c_cy(void *obj);
int		c_tr(void *obj);
t_v3	n_sp(t_hit hit);
t_v3	n_pl(t_hit hit);
t_v3	n_sq(t_hit hit);
t_v3	n_cy(t_hit hit);
t_v3	n_tr(t_hit hit);

#endif
