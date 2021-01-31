/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecutils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:40:54 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/22 17:43:22 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_init(double a, double b, double c)
{
	t_vec	n;

	n.x = a;
	n.y = b;
	n.z = c;
	return (n);
}

double	vec_inner(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	vec_cross(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.z;
	return (c);
}

double	vec_dis(t_vec a, t_vec b)
{
	return (vec_abs(vec_sub(a, b)));
}

double	vec_abs(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
