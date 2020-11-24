/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:59:36 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/26 07:08:15 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t			ft_strlen(const char *s);
int				ft_atoi(char *str);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *buf, int fd);
char			*ft_strcpy(char *dst, char *src);

#endif
