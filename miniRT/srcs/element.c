/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:36 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/17 22:50:39 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*newcam(t_v3 o, t_v3 d, int fov)
{
	t_cam	*nc;

	if (!(nc = (t_cam*)ft_calloc(1, sizeof(t_cam))))
		errmsg(0, "malloc");
	nc->o = o;
	nc->d = d;
	nc->fov = fov;
	nc->hor = vnorm(d);
	nc->ver = vunit(vcross(d, nc->hor));
	nc->hor = vmul(nc->hor, 2 * vabs(d) * tan(M_PI * fov / 360.0));
	nc->ver = vmul(nc->ver, vabs(nc->hor) * (double)g_y / (double)g_x);
	nc->hl = vsub(d, vadd(vmul(nc->hor, 0.5), vmul(nc->ver, 0.5)));
	return (nc);
}

t_light	*newlight(t_v3 o, double inten, int color)
{
	t_light	*nl;

	if (!(nl = (t_light*)ft_calloc(1, sizeof(t_light))))
		errmsg(0, "malloc");
	nl->o = o;
	nl->inten = inten;
	nl->color = color;
	return (nl);
}
