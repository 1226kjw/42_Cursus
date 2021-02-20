/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:25:48 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:08:45 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ci	*new_ci(t_v3 o, t_v3 n, double r, int color)
{
	t_ci	*nc;

	if (!(nc = (t_ci*)ft_calloc(1, sizeof(t_ci))))
		errmsg(0, "malloc");
	nc->o = o;
	nc->n = vunit(n);
	nc->r = r;
	nc->color = color;
	return (nc);
}

double	i_ci(t_ray r, void *obj)
{
	t_ci	c;
	t_pl	pl;
	double	t;
	t_v3	p;

	c = *(t_ci*)obj;
	pl.o = c.o;
	pl.n = vunit(c.n);
	t = i_pl(r, (void*)&pl);
	if (t < 0.0)
		return (-1.0);
	p = vadd(r.o, vmul(r.d, t));
	if (vabs(vsub(p, c.o)) <= c.r)
		return (t);
	return (-1.0);
}

int		c_ci(t_hit hit)
{
	t_ci	*o;

	o = (t_ci*)hit.obj;
	if (o->tex == 1)
	{
		if (((int)fabs(floor(hit.p.x)) % 2) ^ ((int)fabs(floor(hit.p.y)) % 2)
				^ ((int)fabs(floor(hit.p.z)) % 2))
			return (~o->color);
		else
			return (o->color);
	}
	else if (o->tex == 3)
		return (crainbow(hit.p, o->o));
	return (o->color);
}

t_v3	n_ci(t_hit hit)
{
	t_ci	*ci;
	t_v3	n;
	t_v3	p;

	ci = (t_ci*)hit.obj;
	n = vunit(ci->n);
	if (ci->tex == 2)
	{
		p = vsub(ci->o, hit.p);
		n = vadd(n, vmul(vunit(p), AMP * sin(NSCALE * vabs(p))));
	}
	return (vunit(n));
}
