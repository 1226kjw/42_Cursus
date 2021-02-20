/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:28:27 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/20 22:38:21 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vcos(t_v3 a, t_v3 b)
{
	t_v3	au;
	t_v3	bu;

	au = vunit(a);
	bu = vunit(b);
	return (vinner(au, bu));
}

t_v3	vrotx(t_v3 v, double a)
{
	t_v3	m[3];

	m[0] = vset(1, 0, 0);
	m[1] = vset(0, cos(a), -sin(a));
	m[2] = vset(0, sin(a), cos(a));
	return (vset(vinner(m[0], v), vinner(m[1], v), vinner(m[2], v)));
}

t_v3	vroty(t_v3 v, double a)
{
	t_v3	m[3];

	m[0] = vset(cos(a), 0, sin(a));
	m[1] = vset(0, 1, 0);
	m[2] = vset(-sin(a), 0, cos(a));
	return (vset(vinner(m[0], v), vinner(m[1], v), vinner(m[2], v)));
}

t_v3	vrotz(t_v3 v, double a)
{
	t_v3	m[3];

	m[0] = vset(cos(a), -sin(a), 0);
	m[1] = vset(sin(a), cos(a), 0);
	m[2] = vset(0, 0, 1);
	return (vset(vinner(m[0], v), vinner(m[1], v), vinner(m[2], v)));
}
