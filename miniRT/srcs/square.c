/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:28 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:06:37 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sq	*new_sq(t_v3 o, t_v3 n[2], double d, int color)
{
	t_sq	*ret;

	if (!(ret = (t_sq*)ft_calloc(1, sizeof(t_sq))))
		errmsg(0, "error:malloc\n");
	ret->o = o;
	ret->n = vunit(n[0]);
	ret->d = d;
	ret->color = color;
	ret->hor = vunit(n[1]);
	ret->ver = vunit(vcross(n[0], ret->hor));
	ret->hor = vmul(ret->hor, d / 2.0);
	ret->ver = vmul(ret->ver, d / 2.0);
	return (ret);
}

int		parsing_sq(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;
	t_v3	o[3];
	double	d;
	int		color;

	i = 2;
	o[0] = ft_atov(buf, &i);
	o[1] = ft_atov(buf, &i);
	o[2] = vnorm(o[1]);
	d = next_atof(buf, &i);
	color = ft_atoc(buf, &i);
	no = ft_lstnew(SQ, new_sq(o[0], &o[1], d, color));
	((t_sq*)no->obj)->tex = next_atoi(buf, &i);
	ft_lstadd_back(&sn->objs, no);
	if (viseq(((t_sq*)no->obj)->n, vset(0.0, 0.0, 0.0)))
		errmsg(sn, "normal vector cannot be null vector");
	if (((t_sq*)no->obj)->d <= 0)
		errmsg(sn, "valid side length : (0, inf)");
	return (0);
}

double	i_sq(t_ray ray, void *obj)
{
	t_sq	sq;
	double	t;
	t_v3	p;
	t_v3	unit[2];

	sq = *(t_sq*)obj;
	t = i_pl(ray, obj);
	if (t < 0)
		return (-1.0);
	p = vadd(ray.o, vmul(ray.d, t));
	p = vsub(p, sq.o);
	unit[0] = vunit(sq.hor);
	unit[1] = vunit(sq.ver);
	if (fabs(vinner(p, unit[0])) > sq.d / 2 ||
			fabs(vinner(p, unit[1])) > sq.d / 2)
		return (-1.0);
	else
		return (t);
}

int		c_sq(t_hit hit)
{
	t_sq	*o;

	o = (t_sq*)hit.obj;
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

t_v3	n_sq(t_hit hit)
{
	t_sq	*sq;
	t_v3	n;
	t_v3	p;

	sq = (t_sq*)hit.obj;
	n = vunit(sq->n);
	if (sq->tex == 2)
	{
		p = vsub(sq->o, hit.p);
		n = vadd(n, vmul(vunit(p), AMP * sin(NSCALE * vabs(p))));
	}
	return (vunit(n));
}
