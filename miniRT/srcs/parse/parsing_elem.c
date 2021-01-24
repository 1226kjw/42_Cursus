/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:16:01 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/22 22:21:12 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parsing_r(char *line, t_scene *sd)
{
	int		i;

	i = 1;
	if (sd->x || sd->y)
		return (-4);
	while (line[i] && ft_isspace(line[i]))
		i++;
	sd->x = ft_atoi(line + i);
	while (line[i] && !ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	sd->y = ft_atoi(line + i);
	if (sd->x == 0 || sd->y == 0)
		return (-6);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != 0)
		return (-5);
	return (0);
}

int		parsing_c(char *line, t_scene *sd)
{
	int		i;

	i = 1;
	i = i + 1;
	if (line[0] == 0)
		return (0);
	if (sd->ncam == MAXCAM)
		return (-7);
	sd->cam[sd->ncam].pos = vec_init(0,0,1);
	sd->cam[sd->ncam].v = vec_init(0,0,-1);
	sd->cam[sd->ncam].fov = 60;
	sd->ncam++;
	return (0);
}
