/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:53:55 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 13:38:24 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	make_5ver(t_scene *sn, t_py_t p)
{
	t_v3	top;
	t_v3	n;
	t_v3	v[4];

	n = vunit(vcross(p.n[0], p.n[1]));
	top = vadd(p.o, vmul(p.n[0], p.h));
	ft_lstadd_back(&sn->objs, ft_lstnew(SQ, new_sq(p.o, p.n, p.d, p.color)));
	v[0] = vadd(vadd(p.o, vmul(p.n[1], p.d / 2)), vmul(n, p.d / 2));
	v[1] = vadd(vsub(p.o, vmul(p.n[1], p.d / 2)), vmul(n, p.d / 2));
	v[2] = vsub(vsub(p.o, vmul(p.n[1], p.d / 2)), vmul(n, p.d / 2));
	v[3] = vsub(vadd(p.o, vmul(p.n[1], p.d / 2)), vmul(n, p.d / 2));
	ft_lstadd_back(&sn->objs, ft_lstnew(TR, new_tr(top, v[0], v[1], p.color)));
	ft_lstadd_back(&sn->objs, ft_lstnew(TR, new_tr(top, v[1], v[2], p.color)));
	ft_lstadd_back(&sn->objs, ft_lstnew(TR, new_tr(top, v[2], v[3], p.color)));
	ft_lstadd_back(&sn->objs, ft_lstnew(TR, new_tr(top, v[3], v[0], p.color)));
}

int		parsing_py(char *buf, t_scene *sn)
{
	t_py_t	p;
	int		i;

	i = 2;
	p.o = ft_atov(buf, &i);
	p.n[0] = vunit(ft_atov(buf, &i));
	p.n[1] = vnorm(p.n[0]);
	p.d = next_atof(buf, &i);
	p.h = next_atof(buf, &i);
	p.color = ft_atoc(buf, &i);
	if (p.d < 0 || p.h < 0)
		errmsg(sn, "valid size length/hight : (0, inf)");
	make_5ver(sn, p);
	return (0);
}
