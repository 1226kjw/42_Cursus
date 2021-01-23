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
	if (nsphere == MAXSPHERE)
		return (-7);
	sd->sphere[nsphere].pos = vec_init(0.0,0.0,0.0);
	sd->sphere[nsphere].color = vec_init(255.0, 0.0, 0.0);
	sd->sphere[nsphere].r = 0.5;
	sd->nsphere++;
	return (0);
}
