/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:18:16 by jinukim           #+#    #+#             */
/*   Updated: 2021/06/28 21:27:11 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



char	*get_path(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp("PATH", envp[i], 4))
			return (envp[i] + 5);
	return (0);
}

void	ft_exec(char *cmds, char **envp)
{
	char		**p;
	int			i;
	char		*tmp[2];
	char		**cmd;
	struct stat	s;

	i = -1;
	cmd = ft_split(cmds, " ");
	p = ft_split(get_path(envp), ":");
	while (p[++i])
	{
		tmp[0] = ft_strjoin(p[i], "/");
		tmp[1] = ft_strjoin(tmp[0], cmd[0]);
		free(tmp[0]);
		if (stat(tmp[1], &s) == 0)
			execve(tmp[1], cmd, envp);
		free(tmp[1]);
	}
	if (execve(cmd[0], cmd, envp) < 0)
	{
		perror(cmd[0]);
		exit(-1);
	}
}

int		main(int argc, char **argv, char **envp)
{
	int		*fd;
	pid_t	*pid;
	int		s;
	int		i;

	if (argc < 5)
		return (0);
	fd = (int*)malloc(2 * sizeof(int) * (argc - 4));
	pid = (pid_t*)malloc(sizeof(pid_t) * (argc - 3));
	i = 1;
	while (++i < argc - 1)
	{
		printf("%d\n", i);
		pid[i - 2] = fork();
		if (pid[i - 2] == 0)
		{
			if (i == 2)
			{
				pipe(fd);
				pipe_attach(fd, STDOUT_FILENO);
				if (redirect_in(argv[1]) < 0)
					return (-1);
			}
			else if (i == argc - 2)
			{
				pipe_attach(fd + 2 * (i - 3), STDIN_FILENO);
				if (redirect_out(argv[i + 1]) < 0)
					return (-1);
			}
			else
			{
				pipe(fd + 2 * (i - 2));
				pipe_attach(fd + 2 * (i - 2), STDOUT_FILENO);
				pipe_attach(fd + 2 * (i - 3), STDIN_FILENO);
			}
			ft_exec(argv[i], envp);
		}
		waitpid(pid[i - 2], &s, 0);
		if (!WIFEXITED(s))
			exit(EXIT_FAILURE);
	}
	waitpid(pid[argc - 2], &s, 0);
	if (!WIFEXITED(s))
		exit(EXIT_FAILURE);
}
