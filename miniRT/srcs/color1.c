/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 01:00:36 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 01:00:38 by jinukim          ###   ########.fr       */
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
