/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:48:07 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/22 21:51:54 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parsing_sp(char *line, t_scene *sd)
{
	int		i;

	i = 2;
	i = i + 1;
	line[0] = 's';
	if (sd->nsphere == MAXSPHERE)
		return (-7);
	sd->sphere[sd->nsphere].pos = vec_init(0.0,0.0,0.0);
	sd->sphere[sd->nsphere].color = vec_init(255.0, 0.0, 0.0);
	sd->sphere[sd->nsphere].r = 0.5;
	sd->nsphere++;
	return (0);
}
