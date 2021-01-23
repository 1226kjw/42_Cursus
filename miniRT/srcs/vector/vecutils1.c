/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:30:57 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/22 17:48:19 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec	vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	return (vec_add(a, vec_mul(b, -1.0)));
}

t_vec	vec_mul(t_vec a, double b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}

t_vec	vec_unit(t_vec a)
{
	double	r;

	r = 1.0 / vec_abs(a);
	return (vec_mul(a, r));
}

t_vec	vec_normal(t_vec a)
{
	t_vec	n;

	if (a.x == 0.0 && a.y == 0.0)
		n = vec_init(1.0, 0.0, 0.0);
	else
		n = vec_unit(vec_cross(a, vec_init(0.0, 0.0, 1.0)));
	return (n);
}
