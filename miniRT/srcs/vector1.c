/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:28:27 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/20 23:48:02 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vabs(t_v3 a)
{
	return (sqrt(vinner(a, a)));
}

t_v3	vcross(t_v3 a, t_v3 b)
{
	return (vset(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x));
}

t_v3	vunit(t_v3 a)
{
	if (a.x == 0.0 && a.y == 0.0 && a.z == 0.0)
		errmsg(0, "normal vector cannot be null vector");
	return (vmul(a, 1.0 / vabs(a)));
}

t_v3	vnorm(t_v3 a)
{
	if (a.x == 0.0 && a.z == 0.0)
		return (vset(a.y > 0 ? 1.0 : -1.0, 0.0, 0.0));
	else
		return (vunit(vcross(a, vset(0.0, 1.0, 0.0))));
}

int		viseq(t_v3 a, t_v3 b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}
