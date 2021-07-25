/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:31:49 by jinukim           #+#    #+#             */
/*   Updated: 2021/07/24 20:51:42 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

# include <unistd.h>
# include <stdlib.h>

void	*set_ret(const char *str, int count, char **target);
int		get_next_line(int fd, char **line);
size_t	ft_len(const char *s);
char	*ft_dup(const char *s);
int		ft_join(char **s, char *s2);
int		ft_remainder(int fd, char *remain[], char **line);
int		freeall(char *buf, char **line);

#endif
