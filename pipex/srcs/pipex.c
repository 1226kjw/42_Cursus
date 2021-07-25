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

void	free_all(char **strs)
{
	int		i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

void	ft_exec(char *cmds, char **envp)
{
	char		**p;
	int			i;
	char		*tmp;
	char		**cmd;
	struct stat	s;

	i = -1;
	cmd = ft_strap(ft_split(cmds, " "));
	p = ft_split(get_path(envp), ":");
	while (p[++i])
	{
		tmp = ft_strjoin_3(p[i], "/", cmd[0]);
		if (stat(tmp, &s) == 0)
			execve(tmp, cmd, envp);
		free(tmp);
	}
	free_all(p);
	if (stat(cmd[0], &s) == 0 && execve(cmd[0], cmd, envp) < 0)
	{
		perror(cmd[0]);
		exit(errno);
	}
	write(2, "command not found\n", 18);
	free_all(cmd);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	int		*fd;
	pid_t	pid;
	int		s;
	int		i;

	if (argc < 5)
		exit(1);
	fd = (int *)malloc(2 * sizeof(int) * (argc - 4));
	i = 1;
	while (++i < argc - 1)
	{
		if (i != argc - 2)
			pipe(fd + 2 * (i - 2));
		pid = fork();
		if (pid == 0)
		{
			if (i == 2)
			{
				pipe_attach(fd, STDOUT_FILENO);
				if (redirect_in(argv[1], fd) != 0)
					exit(errno);
			}
			else if (i == argc - 2)
			{
				pipe_attach(fd + 2 * (i - 3), STDIN_FILENO);
				if (redirect_out(argv[i + 1], fd) != 0)
					exit(errno);
			}
			else
			{
				pipe_attach(fd + 2 * (i - 2), STDOUT_FILENO);
				pipe_attach(fd + 2 * (i - 3), STDIN_FILENO);
			}
			free(fd);
			ft_exec(argv[i], envp);
		}
		else
		{
			waitpid(pid, &s, WNOWAIT);
			if (!WIFEXITED(s))
				exit(EXIT_FAILURE);
			if (i != argc - 2)
				close(fd[2 * (i - 2) + 1]);
			if (i != 2)
				close(fd[2 * (i - 3)]);
		}
	}
	free(fd);
	waitpid(pid, &s, 0);
	exit(WEXITSTATUS(s));
}
