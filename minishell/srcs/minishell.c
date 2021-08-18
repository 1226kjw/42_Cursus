#include "minishell.h"

int	g_ret = 0;

int	quot_check(char *line)
{
	int		i;
	char	quot;

	quot = 0;
	i = -1;
	while (line[++i])
	{
		if (!quot && (line[i] == '\'' || line[i] == '\"'))
			quot = line[i];
		else if (quot && line[i] == quot)
			quot = 0;
	}
	if (quot)
	{
		g_ret = 1;
		printf("minishell: '%c': syntax error\n", quot);
		free(line);
		return (1);
	}
	return (0);
}

int	mainloop(t_all *all, char *line)
{
	int		i;

	add_history(line);
	if (check_pipe_char(line) || quot_check(line))
		return (1);
	init_pid(all, &all->pid, line);
	pid_loop(all);
	i = -1;
	while (++i < all->idx)
		free(readline(""));
	return (0);
}

char	*ft_stradd(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	*cwd;
	char	*prompt;
	t_all	*all;

	argc = (int)argv[0][0] + 256;
	all = init_all(envp);
	while (argc)
	{
		signal(SIGINT, sig_handler2);
		cwd = ft_stradd(ft_strdup("\033[1;34m"), getcwd(0, 0));
		prompt = ft_strjoin(cwd, "\033[0m$ ");
		free(cwd);
		line = readline(prompt);
		free(prompt);
		signal(SIGINT, SIG_DFL);
		if (line && line[0] != 0 && mainloop(all, line))
			continue ;
		else if (line == NULL)
		{
			set_termcap(0);
			printf("minishell$ exit\n");
			tcsetattr(STDIN_FILENO, TCSANOW, &all->t_old);
			exit(EXIT_SUCCESS);
		}
		free(line);
	}
	return (0);
}
