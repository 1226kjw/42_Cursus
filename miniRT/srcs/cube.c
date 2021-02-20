/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:45:25 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/20 23:39:05 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	make_sq6(t_scene *sn, t_list *nl[], int tex)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		((t_sq*)nl[i]->obj)->tex = tex;
		ft_lstadd_back(&sn->objs, nl[i++]);
	}
}

int		parsing_cu(char *buf, t_scene *sn)
{
	t_v3	o;
	t_v3	n[4];
	double	d;
	int		i[2];
	t_list	*nl[6];

	i[0] = 2;
	o = ft_atov(buf, i);
	n[0] = vunit(ft_atov(buf, i));
	d = next_atof(buf, i);
	i[1] = ft_atoc(buf, i);
	if (d < 0)
		errmsg(sn, "valid side length : (0, inf)");
	n[1] = vnorm(n[0]);
	n[2] = vunit(vcross(n[0], n[1]));
	n[3] = n[0];
	nl[0] = ft_lstnew(SQ, new_sq(vadd(o, vmul(n[0], d / 2)), &n[0], d, i[1]));
	nl[1] = ft_lstnew(SQ, new_sq(vsub(o, vmul(n[0], d / 2)), &n[0], d, i[1]));
	nl[2] = ft_lstnew(SQ, new_sq(vadd(o, vmul(n[1], d / 2)), &n[1], d, i[1]));
	nl[3] = ft_lstnew(SQ, new_sq(vsub(o, vmul(n[1], d / 2)), &n[1], d, i[1]));
	nl[4] = ft_lstnew(SQ, new_sq(vadd(o, vmul(n[2], d / 2)), &n[2], d, i[1]));
	nl[5] = ft_lstnew(SQ, new_sq(vsub(o, vmul(n[2], d / 2)), &n[2], d, i[1]));
	make_sq6(sn, nl, next_atoi(buf, i));
	return (0);
}
