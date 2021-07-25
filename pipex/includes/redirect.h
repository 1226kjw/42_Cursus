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

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct s_pipe
{
	int		*pipe;
	pid_t	pid;
	int		iter;
	int		heredoc;
	char	**argv;
	int		argc;
	int		status;
}			t_pipe;

int		redirect_in(char *file, t_pipe p);
int		redirect_out(char *file, t_pipe p);
void	pipe_attach(int fd[2], int io);

#endif
