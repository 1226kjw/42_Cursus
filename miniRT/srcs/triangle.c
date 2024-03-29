/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:31 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:07:49 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tr	*new_tr(t_v3 a, t_v3 b, t_v3 c, int color)
{
	t_tr	*ret;

	if (!(ret = (t_tr*)ft_calloc(1, sizeof(t_tr))))
		errmsg(0, "error:malloc\n");
	ret->a = a;
	ret->b = b;
	ret->c = c;
	ret->color = color;
	return (ret);
}

int		parsing_tr(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;
	t_tr	*tr;

	i = 2;
	tr = new_tr(ft_atov(buf, &i), ft_atov(buf, &i),
			ft_atov(buf, &i), ft_atoc(buf, &i));
	no = ft_lstnew(TR, (void*)tr);
	no->type = TR;
	tr->tex = next_atoi(buf, &i);
	ft_lstadd_back(&sn->objs, no);
	if (viseq(tr->a, tr->b) || viseq(tr->b, tr->c) || viseq(tr->c, tr->a))
		errmsg(sn, "there is at least one pair dup point on triangle");
	if (vinner(vsub(tr->a, tr->b), vsub(tr->c, tr->b)) ==
			fabs(vabs(vsub(tr->a, tr->b)) * vabs(vsub(tr->c, tr->b))))
		errmsg(sn, "3 points in line cannot make triangle");
	return (0);
}

double	i_tr(t_ray ray, void *obj)
{
	t_pl	pl;
	t_tr	tr;
	double	t;
	t_v3	p;

	tr = *(t_tr*)obj;
	pl.o = tr.a;
	pl.n = vunit(vcross(vsub(tr.b, tr.a), vsub(tr.c, tr.a)));
	t = i_pl(ray, (void*)&pl);
	if (t < 0.0)
		return (-1.0);
	p = vadd(ray.o, vmul(ray.d, t));
	if (issplit(tr.a, tr.b, tr.c, p) || issplit(tr.b, tr.c, tr.a, p) ||
			issplit(tr.c, tr.a, tr.b, p))
		return (-1.0);
	return (t);
}

int		c_tr(t_hit hit)
{
	t_tr	*o;

	o = (t_tr*)hit.obj;
	if (o->tex == 1)
	{
		if (((int)fabs(floor(hit.p.x)) % 2) ^ ((int)fabs(floor(hit.p.y)) % 2)
				^ ((int)fabs(floor(hit.p.z)) % 2))
			return (~o->color);
		else
			return (o->color);
	}
	else if (o->tex == 3)
		return (crainbow(hit.p, o->a));
	return (o->color);
}

t_v3	n_tr(t_hit hit)
{
	t_tr	*tr;
	t_v3	n;
	t_v3	p;

	tr = (t_tr*)hit.obj;
	n = vunit(vcross(vsub(tr->b, tr->a), vsub(tr->c, tr->b)));
	if (tr->tex == 2)
	{
		p = vsub(tr->a, hit.p);
		n = vadd(n, vmul(vunit(p), AMP * sin(NSCALE * vabs(p))));
	}
	return (vunit(n));
}
