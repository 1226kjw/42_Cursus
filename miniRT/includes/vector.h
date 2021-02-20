/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:30:38 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/20 22:38:50 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

typedef struct	s_v3
{
	double	x;
	double	y;
	double	z;
}				t_v3;

typedef struct	s_ray
{
	t_v3	o;
	t_v3	d;
}				t_ray;

t_v3			vset(double x, double y, double z);
t_v3			vadd(t_v3 a, t_v3 b);
t_v3			vsub(t_v3 a, t_v3 b);
t_v3			vmul(t_v3 a, double c);
double			vinner(t_v3 a, t_v3 b);
double			vabs(t_v3 a);
t_v3			vcross(t_v3 a, t_v3 b);
t_v3			vunit(t_v3 a);
t_v3			vnorm(t_v3 a);
int				viseq(t_v3 a, t_v3 b);
double			vcos(t_v3 a, t_v3 b);
t_v3			vrotx(t_v3 v, double a);
t_v3			vroty(t_v3 v, double a);
t_v3			vrotz(t_v3 v, double a);

#endif
