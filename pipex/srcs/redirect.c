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

int	here_doc(t_pipe p)
{
	char	*deli;
	char	*line;
	char	*linenl;
	int		fd[2];

	pipe(fd);
	deli = p.argv[2];
	while (get_next_line(0, &line) != 0)
	{
		if (!ft_strcmp(line, deli))
			break ;
		linenl = ft_strjoin(line, "\n");
		free(line);
		write(fd[1], linenl, ft_strlen(linenl));
		free(linenl);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (0);
}

int	redirect_in(char *file, t_pipe p)
{
	int		fd;

	if (p.heredoc)
		return (here_doc(p));
	else
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			perror(file);
			free(p.pipe);
			return (-1);
		}
		if (dup2(fd, STDIN_FILENO) < 0)
		{
			perror("dup2");
			free(p.pipe);
			return (-1);
		}
		close(fd);
		return (0);
	}
}

int	redirect_out(char *file, t_pipe p)
{
	int		fd;

	if (p.heredoc)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else	
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		free(p.pipe);
		return (errno);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		free(p.pipe);
		return (errno);
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
