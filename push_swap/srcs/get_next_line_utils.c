/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:31:43 by jinukim           #+#    #+#             */
/*   Updated: 2021/07/24 20:51:42 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



size_t	ft_len(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_dup(const char *str)
{
	int		i;
	char	*arr;

	i = -1;
	while (str[++i])
		;
	arr = (char*)malloc((i + 1) * sizeof(char));
	if (!arr)
		return (0);
	arr[i] = 0;
	while (--i >= 0)
		arr[i] = str[i];
	return (arr);
}

int	ft_join(char **s, char *s2)
{
	char	*p;
	int		i;
	int		idx;

	idx = 0;
	if (!set_ret(0, ft_len(*s) + ft_len(s2) + 1, &p))
		return (0);
	i = 0;
	if (*s)
		while ((*s)[i])
			p[idx++] = (*s)[i++];
	i = 0;
	if (s2)
		while (s2[i] && s2[i] != '\n')
			p[idx++] = s2[i++];
	p[idx] = 0;
	if (*s)
		free(*s);
	*s = p;
	return (i);
}

int	ft_remainder(int fd, char *remain[], char **line)
{
	int		i;
	char	*tmp;

	if (!remain[fd])
		return (0);
	i = ft_join(line, remain[fd]);
	tmp = 0;
	if (remain[fd][i] == '\n')
		if (!set_ret(remain[fd] + i + 1, 0, &tmp))
			return (freeall(0, line));
	free(remain[fd]);
	remain[fd] = tmp;
	return (!!tmp);
}

int	freeall(char *buf, char **line)
{
	if (buf)
		free(buf);
	if (line)
	{
		if (*line)
			free(*line);
		*line = 0;
	}
	return (-1);
}
