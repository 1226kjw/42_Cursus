/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:42 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 01:38:09 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	(*g_normal[])(t_hit hit) = {n_sp, n_pl, n_sq, n_cy, n_tr};
double	(*g_inter[])(t_ray ray, void *obj) = {i_sp, i_pl, i_sq, i_cy, i_tr};
int		(*g_color[])(void *obj) = {c_sp, c_pl, c_sq, c_cy, c_tr};

void	colorset_ads(t_scene *sn, t_ray ray, t_hit *hit)
{
	t_ray	lray;
	double	t;
	t_list	*cur;

	hit->acol = cmul(sn->a_light->color, sn->a_light->inten);
	cur = sn->lights;
	while (cur)
	{
		lray.d = vunit(vsub(((t_light*)cur->obj)->o, hit->p));
		lray.o = vadd(hit->p, vmul(lray.d, EPSILON));
		t = closest(lray, sn->objs).t;
		if (t <= 0 || t >= vabs(vsub(((t_light*)cur->obj)->o, lray.o)))
		{
			hit->dcol = cadd(hit->dcol, calc_diffuse(*hit, cur->obj));
			hit->scol = cadd(hit->scol, calc_specular(ray, *hit, cur->obj));
		}
		cur = cur->next;
	}
	p_light(hit, sn);
}

t_hit	calc_pixel(t_ray ray, t_arg *args)
{
	t_hit	hit;

	hit = closest(ray, args->sn->objs);
	if (hit.t >= 0)
	{
		hit.n = g_normal[hit.type](hit);
		if (vinner(hit.n, ray.d) > 0)
			hit.n = vmul(hit.n, -1.0);
		colorset_ads(args->sn, ray, &hit);
		hit.fcol = cadd(ccom(cadd(hit.acol, hit.dcol), hit.ocol), hit.scol);
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

	ft_memset(&hit, 0x00, sizeof(t_hit));
	hit.t = -1;
	hit.type = -1;
	hit.ocol = BG_COLOR;
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
			hit.ocol = g_color[cur->type](cur->obj);
		}
		cur = cur->next;
	}
	return (hit);
}
