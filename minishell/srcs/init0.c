#include "minishell.h"

void	add_cmd(t_cmd **first, t_cmd *new)
{
	t_cmd	*cur;

	if (!*first)
		*first = new;
	else
	{
		cur = *first;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	new->next = 0;
}

t_cmd	*init_cmd(char *line, t_list *envl)
{
	t_cmd	*head;

	head = 0;
	head = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (parse(line, head, envl))
	{
		free(head);
		return (0);
	}
	return (head);
}

void	init_fd(t_fd *fd)
{
	fd->fd_bu[0] = dup(STDIN_FILENO);
	fd->fd_bu[1] = dup(STDOUT_FILENO);
}

void	cat_check(t_all *all, t_pid *pid)
{
	int		i;
	char	**cat;

	pid->total = 0;
	i = 0;
	while (pid->pipe_cmd[pid->total])
	{
		if (i == pid->total)
		{
			cat = ft_split(pid->pipe_cmd[pid->total], " ");
			if (cat[0] && !cat[1] && !ft_strcmp(cat[0], "cat"))
			{
				i++;
				free(pid->pipe_cmd[pid->total]);
			}
			free_all(cat);
		}
		pid->total++;
	}
	all->idx = i;
}
