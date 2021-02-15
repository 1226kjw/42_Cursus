/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:22 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:27:31 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sp	*new_sp(t_v3 o, double r, int color)
{
	t_sp	*ret;

	if (!(ret = (t_sp*)ft_calloc(1, sizeof(t_sp))))
		errmsg(0, "error:malloc\n");
	ret->o = o;
	ret->r = r;
	ret->color = color;
	return (ret);
}

int		parsing_sp(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;

	i = 2;
	no = ft_lstnew(new_sp(ft_atov(buf, &i),
				next_atof(buf, &i), ft_atoc(buf, &i)));
	no->type = SP;
	ft_lstadd_back(&sn->objs, no);
	if (((t_sp*)no->obj)->r < 0)
		errmsg(sn, "valid radius : [0, inf)");
	return (0);
}

double	i_sp(t_ray ray, void *obj)
{
	double	c[3];
	double	disc;
	double	root[2];
	t_sp	ns;
	t_v3	oc;

	ns = *(t_sp*)obj;
	oc = vsub(ray.o, ns.o);
	c[0] = vinner(ray.d, ray.d);
	c[1] = vinner(ray.d, oc);
	c[2] = vinner(oc, oc) - ns.r * ns.r;
	disc = c[1] * c[1] - c[0] * c[2];
	if (disc <= 0)
		return (-1.0);
	root[0] = (-c[1] - sqrt(disc)) / c[0];
	root[1] = (-c[1] + sqrt(disc)) / c[0];
	if (root[0] >= 0)
		return (root[0]);
	else if (root[1] >= 0)
		return (root[1]);
	else
		return (-1.0);
}

int		c_sp(void *obj)
{
	return (((t_sp*)obj)->color);
}

t_v3	n_sp(t_hit hit)
{
	return (vunit(vsub(hit.p, ((t_sp*)hit.obj)->o)));
}
