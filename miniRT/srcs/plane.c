/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:17 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/20 17:43:28 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pl	*new_pl(t_v3 o, t_v3 n, int color, int tex)
{
	t_pl	*ret;

	if (!(ret = (t_pl*)ft_calloc(1, sizeof(t_pl))))
		errmsg(0, "error:malloc\n");
	ret->o = o;
	ret->n = vunit(n);
	ret->color = color;
	ret->tex = tex;
	return (ret);
}

int		parsing_pl(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;

	i = 2;
	no = ft_lstnew(PL, new_pl(ft_atov(buf, &i),
				ft_atov(buf, &i), ft_atoc(buf, &i), next_atoi(buf, &i)));
	ft_lstadd_back(&sn->objs, no);
	if (vabs(((t_pl*)no->obj)->n) == 0.0)
		errmsg(sn, "normal vector cannot be null vector");
	return (0);
}

double	i_pl(t_ray ray, void *obj)
{
	t_pl	pl;
	double	a;
	double	b;

	pl = *(t_pl*)obj;
	a = vinner(pl.n, vsub(pl.o, ray.o));
	b = vinner(pl.n, ray.d);
	if (b == 0.0)
		return (-1.0);
	else if (a / b >= 0)
		return (a / b);
	else
		return (-1);
}

int		c_pl(t_hit hit)
{
	t_pl	*o;

	o = (t_pl*)hit.obj;
	if (o->tex == 1)
	{
		if (((int)fabs(floor(hit.p.x)) % 2) ^ ((int)fabs(floor(hit.p.y)) % 2)
				^ ((int)fabs(floor(hit.p.z)) % 2))
			return (~o->color);
		else
			return (o->color);
	}
	return (o->color);
}

t_v3	n_pl(t_hit hit)
{
	return (vunit(((t_pl*)hit.obj)->n));
}
