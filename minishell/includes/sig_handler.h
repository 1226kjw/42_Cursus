#ifndef SIG_HANDLER_H
# define SIG_HANDLER_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include "libft.h"

# define CLEAR_LINE "\033[6n"

void	sig_handler(int sig);
void	sig_handler2(int sig);
void	set_termios(int i);
void	get_cursor_position(int *col, int *rows);
void	set_line(int col, int row, char *cm, char *ce);
int		ft_putchar(int c);
void	set_termcap(int flag);

#endif