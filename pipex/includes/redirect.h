/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipemng.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:56:12 by jinukim           #+#    #+#             */
/*   Updated: 2021/06/28 17:56:14 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

int		redirect_in(char *file, int *fd);
int		redirect_out(char *file, int *fd);
void	pipe_attach(int fd[2], int io);

#endif
