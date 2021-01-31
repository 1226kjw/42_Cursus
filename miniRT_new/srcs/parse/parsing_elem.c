/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:16:01 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/25 16:07:36 by jinukim          ###   ########.fr       */
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
	i = next_num(line, i);
	sd->y = ft_atoi(line + i);
	if (sd->x == 0 || sd->y == 0)
		return (-6);
	i = next_num(line, i);
	if (line[i] != 0)
		return (-5);
	return (0);
}

int		parsing_c(char *line, t_scene *sd)
{
	int		i;

	if (sd->ncam == MAXCAM)
		return (-7);
	i = next_num(line, 1);	
	sd->cam[sd->ncam].pos.x = ft_atolf(line + i);
	i = next_num(line, i);
	sd->cam[sd->ncam].pos.y = ft_atolf(line + i);
	i = next_num(line, i);
	sd->cam[sd->ncam].pos.z = ft_atolf(line + i);
	i = next_num(line, i);
	sd->cam[sd->ncam].dir.x = ft_atolf(line + i);
	i = next_num(line, i);
	sd->cam[sd->ncam].dir.y = ft_atolf(line + i);
	i = next_num(line, i);
	sd->cam[sd->ncam].dir.z = ft_atolf(line + i);
	i = next_num(line, i);
	sd->cam[sd->ncam].fov = ft_atoi(line + i);
	i = next_num(line, i);
	if ((sd->cam[sd->ncam].dir.x == 0 && sd->cam[sd->ncam].dir.y == 0 &&
			sd->cam[sd->ncam].dir.z == 0) || sd->cam[sd->ncam].fov <= 0 ||
			sd->cam[sd->ncam].fov >= 180)
		return (-6);
	if (line[i] != 0)
		return (-5);
	sd->ncam++;
	return (0);
}
