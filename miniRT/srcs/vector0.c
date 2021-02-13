/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:44 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:28:56 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	vset(double x, double y, double z)
{
	t_v3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_v3	vadd(t_v3 a, t_v3 b)
{
	return (vset(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_v3	vsub(t_v3 a, t_v3 b)
{
	return (vset(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_v3	vmul(t_v3 a, double c)
{
	return (vset(a.x * c, a.y * c, a.z * c));
}

double	vinner(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
