/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:28 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/13 23:58:29 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sq	*new_sq(t_v3 o, t_v3 n, double d, double color)
{
	t_sq	*ret;

	if (!(ret = (t_sq*)ft_calloc(1, sizeof(t_sq))))
		errmsg(0, "error:malloc\n");
	ret->o = o;
	ret->n = n;
	ret->d = d;
	ret->color = color;
	ret->hor = vnorm(n);
	ret->ver = vunit(vcross(n, ret->hor));
	ret->hor = vmul(ret->hor, d / 2.0);
	ret->ver = vmul(ret->ver, d / 2.0);
	return (ret);
}

int		parsing_sq(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;

	i = 2;
	no = ft_lstnew(new_sq(ft_atov(buf, &i),
				ft_atov(buf, &i), next_atof(buf, &i), ft_atoc(buf, &i)));
	no->type = SQ;
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

	t = i_pl(ray, obj);
	if (t < 0)
		return (-1.0);
	p = vadd(ray.o, vmul(ray.d, t));
	p = vsub(p, sq.o);
	unit[0] = vunit(sq.hor);
	unit[1] = vunit(sq.ver);
	if (fabs(vinner(p, unit[0])) > vabs(sq.hor) ||
			fabs(vinner(p, unit[1])) > vabs(sq.ver))
		return (-1.0);
	else
		return (t);
}

int		c_sq(void *obj)
{
	return (((t_sq*)obj)->color);
}

t_v3	n_sq(t_hit hit)
{
	return (vunit(((t_sq*)hit.obj)->n));
}
