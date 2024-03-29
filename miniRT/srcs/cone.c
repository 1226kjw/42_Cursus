/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:26:06 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:08:28 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_co	*new_co(t_v3 o, t_v3 d, double r, double h)
{
	t_co	*nc;

	if (!(nc = (t_co*)ft_calloc(1, sizeof(t_co))))
		errmsg(0, "malloc");
	nc->o = o;
	nc->d = vunit(d);
	nc->r = r;
	nc->h = h;
	return (nc);
}

int		parsing_co(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;
	t_co	*nc;
	t_ci	*ci;

	i = 2;
	no = ft_lstnew(CO, new_co(ft_atov(buf, &i), ft_atov(buf, &i),
					next_atof(buf, &i), next_atof(buf, &i)));
	nc = (t_co*)no->obj;
	if (nc->r < 0 || nc->h < 0)
		errmsg(sn, "valid height/radius : (0, inf)");
	nc->color = ft_atoc(buf, &i);
	nc->tex = next_atoi(buf, &i);
	ft_lstadd_back(&sn->objs, no);
	ft_lstadd_back(&sn->objs,
			ft_lstnew(CI, ci = new_ci(nc->o, nc->d, nc->r, nc->color)));
	ci->tex = nc->tex;
	return (0);
}

double	i_co(t_ray r, void *obj)
{
	t_co	c;
	double	a[4];
	double	disc;
	double	root[2];
	t_v3	w;

	c = *(t_co*)obj;
	w = vsub(r.o, vadd(c.o, vmul(c.d, c.h)));
	a[3] = c.r * c.r / (c.h * c.h);
	a[0] = vinner(r.d, r.d) - (a[3] + 1) * pow(vinner(r.d, c.d), 2);
	a[1] = vinner(r.d, w) - (a[3] + 1) * vinner(r.d, c.d) * vinner(w, c.d);
	a[2] = vinner(w, w) - (a[3] + 1) * pow(vinner(w, c.d), 2);
	disc = a[1] * a[1] - a[0] * a[2];
	if (disc <= 0)
		return (-1.0);
	root[0] = (-a[1] - sqrt(disc)) / a[0];
	root[1] = (-a[1] + sqrt(disc)) / a[0];
	w = vadd(c.o, vmul(c.d, c.h));
	a[0] = vinner(vsub(vadd(r.o, vmul(r.d, root[0])), w), vmul(c.d, -1));
	a[1] = vinner(vsub(vadd(r.o, vmul(r.d, root[1])), w), vmul(c.d, -1));
	if (root[0] >= 0 && a[0] >= 0 && a[0] <= c.h)
		return (root[0]);
	else if (root[1] >= 0 && a[1] >= 0 && a[1] <= c.h)
		return (root[1]);
	return (-1);
}

int		c_co(t_hit hit)
{
	t_co	*o;

	o = (t_co*)hit.obj;
	if (o->tex == 1)
	{
		if (((int)fabs(floor(hit.p.x)) % 2) ^ ((int)fabs(floor(hit.p.y)) % 2)
				^ ((int)fabs(floor(hit.p.z)) % 2))
			return (~o->color);
		else
			return (o->color);
	}
	else if (o->tex == 3)
		return (crainbow(hit.p, vadd(o->o, vmul(o->d, o->h))));
	return (o->color);
}

t_v3	n_co(t_hit hit)
{
	t_co	co;
	t_v3	h;
	t_v3	n;
	double	pt;
	double	x;

	co = *(t_co*)hit.obj;
	pt = vabs(vsub(vadd(co.o, vmul(co.d, co.h)), hit.p));
	x = co.h - pt / cos(atan(co.r / co.h));
	h = vadd(co.o, vmul(co.d, x));
	n = vunit(vsub(hit.p, h));
	if (co.tex == 2)
	{
		h = vsub(vadd(co.o, vmul(co.d, co.h)), hit.p);
		n = vadd(n, vmul(vunit(h), AMP * sin(NSCALE * vabs(h))));
	}
	return (vunit(n));
}
