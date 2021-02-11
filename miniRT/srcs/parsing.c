#include "minirt.h"

int		line_parsing(char *line, t_scene *sn)
{
	char	buf[512];

	ft_strcpy(buf, line);
	free(line);
	if (buf[0] == 0)
		return (0);
	else if (buf[0] == 'R' && ft_isspace(buf[1]))
		return (parsing_r(buf, sn));
	else if (buf[0] == 'A' && ft_isspace(buf[1]))
		return (parsing_a(buf, sn));
	else if (buf[0] == 'c' && ft_isspace(buf[1]))
		return (parsing_c(buf, sn));
	else if (buf[0] == 'l' && ft_isspace(buf[1]))
		return (parsing_l(buf, sn));
	else if (buf[0] == 's' && buf[1] == 'p' && ft_isspace(buf[2]))
		return (parsing_sp(buf, sn));
	else if (buf[0] == 'p' && buf[1] == 'l' && ft_isspace(buf[2]))
		return (parsing_pl(buf, sn));
	else if (buf[0] == 's' && buf[1] == 'q' && ft_isspace(buf[2]))
		return (parsing_sq(buf, sn));
	else if (buf[0] == 'c' && buf[1] == 'y' && ft_isspace(buf[2]))
		return (parsing_cy(buf, sn));
	else if (buf[0] == 't' && buf[1] == 'r' && ft_isspace(buf[2]))
		return (parsing_tr(buf, sn));
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