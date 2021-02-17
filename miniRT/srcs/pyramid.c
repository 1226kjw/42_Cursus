/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:53:55 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 00:59:24 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parsing_py(char *buf, t_scene *sn)
{
	t_v3	o;
	t_v3	n[2];
	double	d[2];
	int		i[2];
	t_list	*nl[5];

	i[0] = 2;
	o = ft_atov(buf, i);
	n[0] = vunit(ft_atov(buf, i));
	n[1] = vnorm(n[0]);
	d[0] = next_atof(buf, i);
	d[1] = next_atof(buf, i);
	i[1] = ft_atoc(buf, i);
	if (d[0] < 0 || d[1] < 0)
		errmsg(sn, "invalid input");

}
