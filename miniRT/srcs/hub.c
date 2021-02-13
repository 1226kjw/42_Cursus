/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:42 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:33:49 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	(*g_inter[7])(t_ray ray, void *obj) = {i_sp, i_pl, i_sq, i_cy, i_tr};
int		(*g_color[7])(void *obj) = {c_sp, c_pl, c_sq, c_cy, c_tr};
//t_v3	(*g_normal[7])(t_ray ray, t_hit hit) = {n_sp, n_pl, n_sq, n_cy, n_tr};

t_hit	calc_pixel(t_ray ray, t_arg *args)
{
	t_hit	hit;

	hit = closest(ray, args->sn->objs);
	return (hit);
}

t_hit	closest(t_ray ray, t_list *objs)
{
	t_hit	hit;
	t_list	*cur;
	double	tmp;

	hit.t = -1;
	hit.type = -1;
	hit.color = BG_COLOR;
	cur = objs;
	while (cur)
	{
		tmp = g_inter[cur->type](ray, cur->obj);
		if (tmp >= 0 && (tmp < hit.t || hit.t == -1.0))
		{
			hit.t = tmp;
			hit.p = vadd(ray.o, vmul(ray.d, tmp));
			hit.type = cur->type;
			hit.obj = cur->obj;
			hit.color = g_color[cur->type](cur->obj);
		}
		cur = cur->next;
	}
	return (hit);
}
