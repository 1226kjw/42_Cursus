/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:49:36 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 00:50:22 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		calc_diffuse(t_hit hit, t_light *cur)
{
	int		color;
	double	inten;

	inten = vcos(hit.n, vunit(vsub(cur->o, hit.p)));
	if (inten < 0)
		inten = 0;
	color = cmul(cur->color, cur->inten * inten);
	return (color);
}

int		calc_specular(t_ray ray, t_hit hit, t_light *cur)
{
	int		color;
	double	inten;
	t_v3	lp;

	lp = vunit(vsub(cur->o, hit.p));
	inten = vinner(vunit(ray.d),
			vunit(vadd(lp, vmul(hit.n, -2 * vinner(lp, hit.n)))));
	inten = inten < 0 ? 0 : pow(inten, 32);
	color = cmul(cur->color, cur->inten * inten);
	return (color);
}

void	p_light(t_hit *hit, t_scene *sn)
{
	t_list	*cur;
	double	t;
	double	inten;
	t_ray	lray;
	t_light	*p;

	cur = sn->p_lights;
	while (cur)
	{
		inten = 0;
		p = (t_light*)cur->obj;
		lray.d = vunit(vmul(p->o, -1));
		lray.o = vadd(hit->p, vmul(lray.d, EPSILON));
		t = closest(lray, sn->objs).t;
		if (t <= 0)
			inten = vcos(hit->n, lray.d);
		if (inten < 0)
			inten = 0;
		hit->dcol = cadd(hit->dcol, cmul(((t_light*)cur->obj)->color,
					((t_light*)cur->obj)->inten * inten));
		cur = cur->next;
	}
}
