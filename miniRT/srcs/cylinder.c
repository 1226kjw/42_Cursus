/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:26 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:07:34 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cy	*new_cy(t_v3 o, t_v3 d, double r, double h)
{
	t_cy	*ret;

	if (!(ret = (t_cy*)ft_calloc(1, sizeof(t_cy))))
		errmsg(0, "error:malloc\n");
	ret->o = o;
	ret->d = vunit(d);
	ret->r = r;
	ret->h = h;
	return (ret);
}

int		parsing_cy(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;
	t_cy	*nc;
	t_ci	*c[2];

	i = 2;
	no = ft_lstnew(CY, new_cy(ft_atov(buf, &i), ft_atov(buf, &i),
				next_atof(buf, &i), next_atof(buf, &i)));
	nc = (t_cy*)no->obj;
	if (nc->r < 0 || nc->h < 0)
		errmsg(sn, "valid height/radius : [0, inf)");
	nc->color = ft_atoc(buf, &i);
	nc->tex = next_atoi(buf, &i);
	ft_lstadd_back(&sn->objs, no);
	ft_lstadd_back(&sn->objs,
		ft_lstnew(CI, c[0] = new_ci(nc->o, nc->d, nc->r, nc->color)));
	ft_lstadd_back(&sn->objs, ft_lstnew(CI, c[1] = new_ci(vadd(nc->o,
						vmul(nc->d, nc->h)), nc->d, nc->r, nc->color)));
	c[0]->tex = nc->tex;
	c[1]->tex = nc->tex;
	return (0);
}

double	i_cy(t_ray r, void *obj)
{
	t_cy	c;
	double	a[3];
	double	disc;
	double	root[2];
	t_v3	w;

	c = *(t_cy*)obj;
	w = vsub(r.o, c.o);
	a[0] = vinner(r.d, r.d) - pow(vinner(r.d, vunit(c.d)), 2);
	a[1] = vinner(r.d, w) - vinner(r.d, vunit(c.d)) * vinner(w, vunit(c.d));
	a[2] = vinner(w, w) - pow(vinner(w, vunit(c.d)), 2) - c.r * c.r;
	disc = a[1] * a[1] - a[0] * a[2];
	if (disc <= 0)
		return (-1.0);
	root[0] = (-a[1] - sqrt(disc)) / a[0];
	root[1] = (-a[1] + sqrt(disc)) / a[0];
	a[0] = vinner(vsub(vadd(r.o, vmul(r.d, root[0])), c.o), vmul(c.d, c.h));
	a[1] = vinner(vsub(vadd(r.o, vmul(r.d, root[1])), c.o), vmul(c.d, c.h));
	if (root[0] >= 0 && a[0] >= 0 && a[0] <= c.h * c.h)
		return (root[0]);
	else if (root[1] >= 0 && a[1] >= 0 && a[1] <= c.h * c.h)
		return (root[1]);
	return (-1.0);
}

int		c_cy(t_hit hit)
{
	t_cy	*o;

	o = (t_cy*)hit.obj;
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

t_v3	n_cy(t_hit hit)
{
	t_cy	*cy;
	t_v3	cq;
	t_v3	n;
	t_v3	p;

	cy = (t_cy*)hit.obj;
	cq = vmul(cy->d, vinner(vsub(hit.p, cy->o), cy->d));
	n = vunit(vsub(hit.p, vadd(cy->o, cq)));
	if (cy->tex == 2)
	{
		p = vsub(cy->o, hit.p);
		n = vadd(n, vmul(vunit(p), AMP * sin(NSCALE * vabs(p))));
	}
	return (vunit(n));
}
