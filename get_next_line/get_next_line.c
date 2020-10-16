/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:28:28 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/16 18:37:36 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			n;

	p = malloc(count * size);
	if (!p)
		return (p);
	n = 0;
	while (n < size * count)
		((unsigned char*)p)[n++] = 0;
	return (p);
}

int		get_next_line(int fd, char **line)
{
	static t_buf	buf[OPEN_MAX];

	if (!line || fd >= OPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	*line = (char*)ft_calloc(1, sizeof(char));
	if (!buf[fd].buf)
		if (!(buf[fd].buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (-1);
	while (buf[fd].n || (buf[fd].n += read(fd, buf[fd].buf, BUFFER_SIZE)) > 0)
		if (digest(fd, buf, line))
			return (1);
	if (buf[fd].n < 0)
	{
		free(*line);
		*line = 0;
	}
	free(buf[fd].buf);
	buf[fd].buf = 0;
	return (buf[fd].n);
}
