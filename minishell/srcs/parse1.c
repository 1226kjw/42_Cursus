#include "minishell.h"

extern int	g_ret;

int	parse_red(char *buf, t_cmd *cmd, t_parse *p)
{
	int		ret;

	while (buf[++p->i])
	{
		if (!p->quot && (buf[p->i] == '\'' || buf[p->i] == '\"'))
			p->quot = buf[p->i];
		else if (p->quot && buf[p->i] == p->quot)
			p->quot = 0;
		if (!p->quot && (buf[p->i] == '<' || buf[p->i] == '>'))
		{
			if (buf[p->i + 1] == buf[p->i])
				cmd->parse = ft_strip(ft_split(buf + p->i + 2, " <>"));
			else
				cmd->parse = ft_strip(ft_split(buf + p->i + 1, " <>"));
			if (!cmd->parse[0])
			{
				printf("minishell: syntax error near unexpected token 'newline'\n");
				cmd->ret = 1;
				g_ret = 258;
				ret = 1;
			}
			if (buf[p->i] == '<' && buf[p->i + 1] != '>')
			{
				if (buf[p->i + 1] == '<'
					&& (buf[p->i + 2] != '<' && buf[p->i + 2] != '>'))
				{
					if (heredoc_all(cmd, buf, p->i + 2))
						ret = 2;
				}
				else if (buf[p->i + 1] != '<')
				{
					if (redin(cmd))
						ret = 1;
				}
			}
			else if (buf[p->i + 1] == '>')
			{
				if (redout_append(cmd, &cmd->append, &cmd->redout, O_APPEND))
					ret = 2;
			}
			else if (redout_append(cmd, &cmd->redout, &cmd->append, O_TRUNC))
				ret = 2;
			ret = 0;
			if (ret == 1)
				ret = 1;
			else if (ret == 2)
				ret = 2;
			if (buf[p->i + 1] == buf[p->i])
				buf[p->i + 1] = ' ';
			buf[p->i++] = ' ';
			while (buf[p->i] == ' ')
				p->i++;
			while (buf[p->i] && (p->quot || buf[p->i] != ' '))
			{
				if (!p->quot && (buf[p->i] == '\'' || buf[p->i] == '\"'))
					p->quot = buf[p->i];
				else if (p->quot && buf[p->i] == p->quot)
					p->quot = 0;
				if (!p->quot && (buf[p->i] == '<' || buf[p->i] == '>'))
				{
					printf("minishell: syntax error near unexpected token '%c'\n",
						buf[p->i]);
					g_ret = 258;
					cmd->ret = 1;
					ret = 1;
				}
				buf[p->i++] = ' ';
				if (buf[p->i - 1] == ' ' && (buf[p->i] == '<' || buf[p->i] == '>'))
					break ;
			}
			p->i--;
			ret = 0;
			free_all(cmd->parse);
			if (ret == 1)
				return (1);
			else if (ret == 2)
				continue ;
		}
	}
	return (0);
}

int	parse(char *line, t_cmd *cmd, t_list *envl)
{
	char		buf[10000];
	t_parse		*p;

	p = (t_parse *)ft_calloc(1, sizeof(t_parse));
	p->i = -1;
	cmd->redin = -1;
	cmd->redout = -1;
	cmd->append = -1;
	cmd->delimit = -1;
	cmd->ret = 0;
	ft_bzero(buf, 10000);
	parse_var(buf, line, envl);
	if (parse_red(buf, cmd, p))
	{
		free(p);
		return (1);
	}
	cmd->arg = ft_strip(ft_split(buf, " "));
	free(p);
	return (0);
}
