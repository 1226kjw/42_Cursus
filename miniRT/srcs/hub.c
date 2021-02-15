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


t_hit	calc_pixel(t_ray ray, t_arg *args)
{
	t_hit	hit;
	t_v3	(*normal[7])(t_hit hit) = {n_sp, n_pl, n_sq, n_cy, n_tr};

	hit = closest(ray, args->sn->objs);
	if (hit.t >= 0)
	{
		printf("here");
		hit.n = normal[hit.type](hit);
		hit.acol = cmul(args->sn->a_light->color, args->sn->a_light->inten);
		hit.dcol = calc_diffuse(ray, hit, args->sn);
		hit.scol = calc_specular(ray, hit, args->sn);
		hit.fcol = ccom(cadd(cadd(hit.acol, hit.dcol), hit.scol), hit.ocol);
	}
	else
		hit.fcol = hit.ocol;
	return (hit);
}

t_hit	closest(t_ray ray, t_list *objs)
{
	t_hit	hit;
	t_list	*cur;
	double	tmp;
	double	(*inter[])(t_ray ray, void *obj) = {i_sp, i_pl, i_sq, i_cy, i_tr};
	int		(*color[])(void *obj) = {c_sp, c_pl, c_sq, c_cy, c_tr};

	hit.t = -1;
	hit.type = -1;
	hit.ocol = BG_COLOR;
	cur = objs;
	while (cur)
	{
		tmp = inter[cur->type](ray, cur->obj);
		if (tmp >= 0 && (tmp < hit.t || hit.t == -1.0))
		{
			hit.t = tmp;
			hit.p = vadd(ray.o, vmul(ray.d, tmp));
			hit.type = cur->type;
			hit.obj = cur->obj;
			hit.ocol = color[cur->type](cur->obj);
		}
		cur = cur->next;
	}
	return (hit);
}
