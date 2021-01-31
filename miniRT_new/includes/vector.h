/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:24:49 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/21 18:16:06 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include "minirt.h"


t_vec			vec_init(double a, double b, double c);
t_vec			vec_add(t_vec a, t_vec b);
t_vec			vec_sub(t_vec a, t_vec b);
t_vec			vec_mul(t_vec a, double b);
t_vec			vec_unit(t_vec a);
t_vec			vec_normal(t_vec a);
double			vec_inner(t_vec a, t_vec b);
t_vec			vec_cross(t_vec a, t_vec b);
double			vec_dis(t_vec a, t_vec b);
double			vec_abs(t_vec a);

#endif
