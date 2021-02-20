/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 01:00:36 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:11:28 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		cmul(int a, double i)
{
	int		c[3];

	if (i <= 0.0)
		return (0);
	c[0] = (int)(cred(a) * i);
	c[1] = (int)(cgreen(a) * i);
	c[2] = (int)(cblue(a) * i);
	return (cset(c[0], c[1], c[2]));
}

int		ccom(int a, int b)
{
	int		c[3];

	c[0] = cred(a) * cred(b) / 255;
	c[1] = cgreen(a) * cgreen(b) / 255;
	c[2] = cblue(a) * cblue(b) / 255;
	return (cset(c[0], c[1], c[2]));
}

int		cfil(int a)
{
	double	y;
	int		c;

	if (!g_filter)
		return (a);
	y = (0.299 * cred(a) + 0.587 * cgreen(a) +
			0.114 * cblue(a)) / 255;
	c = cset((y + 1.402 * g_cr) * 255,
			(y - 0.34414 * g_cb - 0.71414 * g_cr) * 255,
			(y + 1.772 * g_cb) * 255);
	return (c);
}

int		caverage(int a, int b, int c, int d)
{
	int		rgb[3];

	rgb[0] = cred(a) + cred(b) + cred(c) + cred(d);
	rgb[1] = cgreen(a) + cgreen(b) + cgreen(c) + cgreen(d);
	rgb[2] = cblue(a) + cblue(b) + cblue(c) + cblue(d);
	return (cset(rgb[0] / 4, rgb[1] / 4, rgb[2] / 4));
}

int		crainbow(t_v3 p, t_v3 o)
{
	double	d;

	d = vabs(vsub(p, o));
	while (d >= RSCALE)
		d -= RSCALE;
	if (d < RSCALE * 1 / 7)
		return (RED);
	else if (d < RSCALE * 2 / 7)
		return (ORANGE);
	else if (d < RSCALE * 3 / 7)
		return (YELLOW);
	else if (d < RSCALE * 4 / 7)
		return (GREEN);
	else if (d < RSCALE * 5 / 7)
		return (BLUE);
	else if (d < RSCALE * 6 / 7)
		return (INDIGO);
	else if (d < RSCALE)
		return (VIOLET);
	return (0);
}
