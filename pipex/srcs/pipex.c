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

void	init_pipe(int argc, char **argv, t_pipe *p)
{
	p->argc = argc;
	p->argv = argv;
	p->iter = 1;
	if (BONUS && !ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
			exit(1);
		p->heredoc = 1;
		p->iter++;
	}
	p->pipe = (int *)malloc(2 * sizeof(int) * (argc - 4 - p->heredoc));
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

void	on_child(t_pipe p, char **envp)
{
	if (p.iter - p.heredoc == 2)
	{
		pipe_attach(p.pipe, STDOUT_FILENO);
		if (redirect_in(p.argv[1 + p.heredoc], p) != 0)
			exit(errno);
	}
	else if (p.iter == p.argc - 2)
	{
		pipe_attach(p.pipe + 2 * (p.iter - p.heredoc - 3), STDIN_FILENO);
		if (redirect_out(p.argv[p.iter + 1], p) != 0)
			exit(errno);
	}
	else
	{
		pipe_attach(p.pipe + 2 * (p.iter - p.heredoc - 2), STDOUT_FILENO);
		pipe_attach(p.pipe + 2 * (p.iter - p.heredoc - 3), STDIN_FILENO);
	}
	free(p.pipe);
	ft_exec(p.argv[p.iter], envp);
}

void	on_parent(t_pipe p, int *s)
{
	waitpid(p.pid, s, WNOWAIT);
	if (p.iter != p.argc - 2)
		close(p.pipe[2 * (p.iter - p.heredoc - 2) + 1]);
	if (p.iter - p.heredoc != 2)
		close(p.pipe[2 * (p.iter - p.heredoc - 3)]);
	if (p.iter == p.argc - 2)
	{
		free(p.pipe);
		waitpid(p.pid, s, 0);
		exit(WEXITSTATUS(*s));
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		s;
	t_pipe	p;

	if (argc < 5)
		exit(1);
	init_pipe(argc, argv, &p);
	while (++p.iter < argc - 1)
	{
		if (p.iter != argc - 2)
			pipe(p.pipe + 2 * (p.iter - p.heredoc - 2));
		p.pid = fork();
		if (p.pid == 0)
			on_child(p, envp);
		else
			on_parent(p, &s);
	}
}
