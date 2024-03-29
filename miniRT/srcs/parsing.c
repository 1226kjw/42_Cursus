/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:03 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 22:26:11 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parsing_obj(char *buf, t_scene *sn)
{
	if (buf[0] == 's' && buf[1] == 'p' && ft_isspace(buf[2]))
		return (parsing_sp(buf, sn));
	else if (buf[0] == 'p' && buf[1] == 'l' && ft_isspace(buf[2]))
		return (parsing_pl(buf, sn));
	else if (buf[0] == 's' && buf[1] == 'q' && ft_isspace(buf[2]))
		return (parsing_sq(buf, sn));
	else if (buf[0] == 'c' && buf[1] == 'y' && ft_isspace(buf[2]))
		return (parsing_cy(buf, sn));
	else if (buf[0] == 't' && buf[1] == 'r' && ft_isspace(buf[2]))
		return (parsing_tr(buf, sn));
	else if (buf[0] == 'c' && buf[1] == 'u' && ft_isspace(buf[2]))
		return (parsing_cu(buf, sn));
	else if (buf[0] == 'p' && buf[1] == 'y' && ft_isspace(buf[2]))
		return (parsing_py(buf, sn));
	else if (buf[0] == 'c' && buf[1] == 'o' && ft_isspace(buf[2]))
		return (parsing_co(buf, sn));
	return (1);
}

int		parsing_f(char *buf)
{
	int		i;

	i = 1;
	g_filter = 1;
	g_cb = next_atof(buf, &i);
	g_cr = next_atof(buf, &i);
	return (1);
}

int		line_parsing(char *line, t_scene *sn)
{
	char	buf[512];

	printf("%s\n", line);
	ft_strcpy(buf, line);
	free(line);
	if (buf[0] == 0 || buf[0] == '#')
		return (0);
	else if ((buf[0] == 'R' || buf[0] == 'A') && ft_isspace(buf[1]))
		return (buf[0] == 'R' ? parsing_r(buf, sn) : parsing_a(buf, sn));
	else if ((buf[0] == 'c' || buf[0] == 'l') && ft_isspace(buf[1]))
		return (buf[0] == 'c' ? parsing_c(buf, sn) : parsing_l(buf, sn));
	else if ((buf[0] == 'p' || buf[0] == 'f') && ft_isspace(buf[1]))
		return (buf[0] == 'p' ? parsing_p(buf, sn) : parsing_f(buf));
	else if (!parsing_obj(buf, sn))
		return (0);
	return (-1);
}

int		parsing(int fd, t_scene *sn)
{
	char	*line;
	int		i;

	while ((i = get_next_line(fd, &line)) == 1)
		if ((i = line_parsing(line, sn)) < 0)
			return (i);
	if (i == -1 || (i = line_parsing(line, sn)) < 0)
		return (i);
	return (0);
}
