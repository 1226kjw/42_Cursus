/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:26 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:21:18 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cy	*new_cy(t_v3 o, t_v3 d, double r, double h)
{
	t_cy	*ret;

	if (!(ret = (t_cy*)ft_calloc(1, sizeof(t_cy))))
		errmsg(0, "error:malloc\n");
	ret->o = o;
	ret->d = d;
	ret->r = r;
	ret->h = h;
	return (ret);
}

int		parsing_cy(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;

	i = 2;
	no = ft_lstnew(new_cy(ft_atov(buf, &i), ft_atov(buf, &i),
				next_atof(buf, &i), next_atof(buf, &i)));
	no->type = CY;
	((t_cy*)(no->obj))->color = ft_atoc(buf, &i);
	ft_lstadd_back(&sn->objs, no);
	if (viseq(((t_cy*)no->obj)->d, vset(0.0, 0.0, 0.0)))
		errmsg(sn, "normal vector cannot be null vector");
	((t_cy*)no->obj)->d = vunit(((t_cy*)no->obj)->d);
	if (((t_cy*)no->obj)->r < 0 || ((t_cy*)no->obj)->r < 0)
		errmsg(sn, "valid height/radius : [0, inf)");
	return (0);
}

double	i_cy(t_ray r, void *obj)
{
	t_cy	cy;
	double	c[3];
	double	disc;
	double	root[2];
	t_v3	w;

	cy = *(t_cy*)obj;
	w = vsub(r.o, cy.o);
	c[0] = vinner(r.d, r.d) - pow(vinner(r.d, vunit(cy.d)), 2);
	c[1] = vinner(r.d, w) - vinner(r.d, vunit(cy.d)) * vinner(w, vunit(cy.d));
	c[2] = vinner(w, w) - pow(vinnr(w, vunit(cy.d)), 2) - cy.r * cy.r;
	disc = c[1] * c[1] - c[0] * c[2];
	if (disc <= 0)
		return (-1.0);
	root[0] = (-b - sqrt(disc)) / a;
	root[1] = (-b + sqrt(disc)) / a;
	if (root[0])
		return (root[0]);
	else if (root[1])
		return (root[1]);
	else
		return (-1.0);
}

int		c_cy(void *obj)
{
	return (((t_cy*)obj)->color);
}

t_v3	n_cy(t_hit hit)
{
	t_cy	cy;
	t_v3	cq;

	cy = *(t_cy*)hit.obj;
	cq = vmul(cy.d, vinner(vsub(hit.p, cy.o), cy.d));
	return (vunit(vsub(hit.p, vadd(cy.o, cq))));
}
