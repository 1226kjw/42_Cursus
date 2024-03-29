#include "minishell.h"

extern int	g_ret;

int	redout_append(t_cmd *cmd, int *this, int *other, int flag)
{
	if (*this > -1)
		close(*this);
	*this = open(cmd->parse[0], O_CREAT | flag | O_WRONLY, 0644);
	if (*this < 0)
	{
		g_ret = *this;
		cmd->ret = 1;
		exit(EXIT_SUCCESS);
		return (1);
	}
	if (*other > -1)
	{
		close(*other);
		*other = -1;
	}
	return (0);
}
