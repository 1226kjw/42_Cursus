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
	if (((t_cy*)no->obj)->r < 0 || ((t_cy*)no->obj)->r < 0)
		errmsg(sn, "valid height/radius : [0, inf)");
	return (0);
}

/*
void	cy_quad(t_ray r, t_cy cy, t_v3 *coe)
{
	t_v3	u;
	t_v3	v;
	t_v3	h;

	u = vunit(r.d);
	v = vsub(r.o, cy.o);
	h = cy.d;
	coe->x = 1 - vinner(u, h) * vinner(u, h);
	coe->y = 2 * (vinner(u, v) - vinner(u, h) * vinner(v, h));
	coe->z = vinner(v, v) - vinner(v, h) * vinner(v, h) - cy.r * cy.r;
}
*/

double	i_cy(t_ray r, void *obj)
{
	t_cy	cy;
	double	a;
	double	b;
	double	c;
	double	disc;

	cy = *(t_cy*)obj;
	a = 1.0 - vinner(vunit(r.d), cy.d) * vinner(vunit(r.d), cy.d);
	b = vinner(vunit(r.d), vsub(r.o, cy.o)) - vinner(vunit(r.d), cy.d) *
			vinner(vsub(r.o, cy.o), cy.o);
	c = vinner(vsub(r.o, cy.o), vsub(r.o, cy.o));
	disc = b * b - a * c;
	if (disc <= 0)
		return (-1.0);
	disc = sqrt(disc);
	if ((-b - disc) / a >= 0)
		return ((-b - disc) / a);
	else if ((-b + disc) / a >= 0)
		return ((-b + disc) / a);
	else
		return (-1.0);
}

int		c_cy(void *obj)
{
	return (((t_cy*)obj)->color);
}
