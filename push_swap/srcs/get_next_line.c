/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:28:28 by jinukim           #+#    #+#             */
/*   Updated: 2021/07/24 22:03:49 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*set_ret(const char *str, int count, char **target)
{
	if (str)
		*target = ft_dup(str);
	else
		*target = (char*)malloc(sizeof(char) * count);
	return (*target);
}

int		read_ret(int fd, char *buf, int buffer, int *i)
{
	*i = read(fd, buf, buffer);
	return (*i);
}

int	get_next_line(int fd, char **line)
{
	static char	*remain[OPEN_MAX];
	char		*buf;
	int			i;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!set_ret("", 0, line))
		return (-1);
	i = ft_remainder(fd, remain, line);
	if (i != 0)
		return (i);
	if (!set_ret(0, BUFFER_SIZE + 1, &buf))
		return (freeall(0, line));
	while (!remain[fd] && read_ret(fd, buf, BUFFER_SIZE, &i) > 0)
	{
		buf[i] = 0;
		i = ft_join(line, buf);
		if (buf[i] == '\n')
			if (!set_ret(buf + i + 1, 0, &remain[fd]))
				return (freeall(buf, line));
	}
	free(buf);
	if (!remain[fd])
		return (i);
	return (1);
}
