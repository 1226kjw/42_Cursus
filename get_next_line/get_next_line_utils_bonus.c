/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:31:43 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/16 17:08:07 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_gnllen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnljoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		idx;

	idx = 0;
	i = -1;
	if (!(p = (char*)malloc(((s1 ? ft_gnllen(s1) : 0) + (s2 ? ft_gnllen(s2) : 0)
			+ 1) * sizeof(char))))
		return (0);
	if (s1)
		while (s1[++i])
			p[idx++] = s1[i];
	i = -1;
	if (s2)
		while (s2[++i])
			p[idx++] = s2[i];
	p[idx] = 0;
	if (s1)
		free(s1);
	return (p);
}

int		digest(int fd, t_buf *buf, char **line)
{
	int				i;
	int				flag;

	buf[fd].buf[buf[fd].n + buf[fd].out] = 0;
	i = buf[fd].out - 1;
	flag = 0;
	while (buf[fd].buf[++i])
		if (buf[fd].buf[i] == '\n')
		{
			buf[fd].buf[i] = 0;
			flag = 1;
			break ;
		}
	*line = ft_gnljoin(*line, buf[fd].buf + buf[fd].out);
	buf[fd].n -= flag ? i - buf[fd].out + 1 : buf[fd].n;
	buf[fd].out = i == BUFFER_SIZE ? 0 : i + 1;
	if (!buf[fd].n)
		buf[fd].out = 0;
	return (flag);
}
