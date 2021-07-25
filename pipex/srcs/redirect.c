/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:55:58 by jinukim           #+#    #+#             */
/*   Updated: 2021/06/28 21:17:13 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

int		redirect_in(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("dup2");
		return (-1);
	}
	close(fd);
	return (0);
}

int		redirect_out(char *file)
{
	int		fd;

	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		return (-1);
	}
	close(fd);
	return (0);
}

void	pipe_attach(int fd[2], int io)
{
	dup2(fd[io], io);
	close(fd[0]);
	close(fd[1]);
}
