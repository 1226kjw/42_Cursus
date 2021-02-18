/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:41:53 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 22:25:25 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		cred(int a)
{
	return ((a >> 16) & 0xff);
}

int		cgreen(int a)
{
	return ((a >> 8) & 0xff);
}

int		cblue(int a)
{
	return (a & 0xff);
}

int		cset(int r, int g, int b)
{
	int		color;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	color = r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}

int		cadd(int a, int b)
{
	int		c[3];

	c[0] = cred(a) + cred(b);
	c[1] = cgreen(a) + cgreen(b);
	c[2] = cblue(a) + cblue(b);
	return (cset(c[0], c[1], c[2]));
}
