/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 22:17:14 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/16 17:15:27 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_buf
{
	char	*buf;
	int		out;
	int		n;
}				t_buf;
void			*ft_calloc(size_t count, size_t size);
int				get_next_line(int fd, char **line);
size_t			ft_gnllen(const char *s);
char			*ft_gnljoin(char *s1, char *s2);
int				digest(int fd, t_buf *buf, char **line);

#endif
