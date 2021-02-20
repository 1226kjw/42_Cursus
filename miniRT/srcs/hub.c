/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:42 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/20 23:33:04 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	(*g_normal[])(t_hit hit) = {n_sp, n_pl, n_sq, n_cy, n_tr, n_ci, n_co};
double	(*g_inter[])(t_ray ray, void *) =
{i_sp, i_pl, i_sq, i_cy, i_tr, i_ci, i_co};
int		(*g_color[])(t_hit hit) = {c_sp, c_pl, c_sq, c_cy, c_tr, c_ci, c_co};

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

void	anti_aliasing(t_hit *hit, t_ray ray, t_arg *args)
{
	t_ray	r[4];
	int		anti[4];
	int		i;

	r[0] = (t_ray){ray.o, vsub(ray.d, vadd(vmul(args->cam->hor, 0.3 / g_x),
				vmul(args->cam->ver, 0.3 / g_y)))};
	r[1] = (t_ray){ray.o, vsub(ray.d, vadd(vmul(args->cam->hor, 0.3 / g_x),
				vmul(args->cam->ver, -0.3 / g_y)))};
	r[2] = (t_ray){ray.o, vsub(ray.d, vadd(vmul(args->cam->hor, -0.3 / g_x),
				vmul(args->cam->ver, 0.3 / g_y)))};
	r[3] = (t_ray){ray.o, vsub(ray.d, vadd(vmul(args->cam->hor, -0.3 / g_x),
				vmul(args->cam->ver, -0.3 / g_y)))};
	i = -1;
	while (++i < 4)
		anti[i] = closest(r[i], args->sn->objs).ocol;
	hit->ocol = caverage(anti[0], anti[1], anti[2], anti[3]);
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
		anti_aliasing(&hit, ray, args);
		hit.fcol = cadd(cfil(ccom(cadd(hit.acol, hit.dcol), hit.ocol)),
				hit.scol);
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
			hit.ocol = g_color[cur->type](hit);
		}
		cur = cur->next;
	}
	return (hit);
}
