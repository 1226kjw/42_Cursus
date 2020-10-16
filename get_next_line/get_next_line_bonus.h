/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 22:17:14 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/17 03:58:27 by jinukim          ###   ########.fr       */
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

int			get_next_line(int fd, char **line);
size_t		ft_len(const char *s);
char		*ft_dup(const char *s);
int			ft_join(char **s, char *s2);
int			ft_remainder(int fd, char *remain[], char **line);
int			freeall(char *buf, char **line);
#endif
