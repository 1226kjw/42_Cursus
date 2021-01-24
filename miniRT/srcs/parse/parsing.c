/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:41:03 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/22 18:12:01 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		line_parsing(char *line, t_scene *sd)
{
	char	buf[256];

	ft_strcpy(buf, line);
	free(line);
	if (buf[0] == 0)
		return (0);
	else if (buf[0] == 'R')
		return (parsing_r(buf, sd));
//	else if (buf[0] == 'A')
//		return (parsing_a(buf, sd));
	else if (buf[0] == 'c' && buf[1] != 'y')
		return (parsing_c(buf, sd));
//	else if (buf[0] == 'l')
//		return (parsing_l(buf, sd));
	else if (buf[0] == 's' && buf[1] == 'p')
		return (parsing_sp(buf, sd));
//	else if (buf[0] == 'p' && buf[1] == 'l')
//		return (parsing_pl(buf, sd));
//	else if (buf[0] == 's' && buf[1] == 'q')
//		return (parsing_sq(buf, sd));
//	else if (buf[0] == 'c' && buf[1] == 'y')
//		return (parsing_cy(buf, sd));
//	else if (buf[0] == 't' && buf[1] == 'r')
//		return (parsing_ty(buf, sd));
	return (-3);
}

int		parsing(int fd, t_scene *sd)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) > 0)
		if ((ret = line_parsing(line, sd)) < 0)
			return (ret);
	if (ret == -1 || (ret = line_parsing(line, sd)) < 0)
		return (ret);
	return (0);
}
