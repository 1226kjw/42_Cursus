#include "sig_handler.h"

extern int	g_ret;

void	sig_handler(int sig)
{
	if (sig)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
	g_ret = 1;
}

void	sig_handler2(int sig)
{
	if (sig)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_ret = 1;
}
