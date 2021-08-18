#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	free_all(char **strs);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspdigit(char *str);
void	err_msg(char *str);
int		check_cap(char *arg, char *builtin);
int		check_pipe_char(char *arg);

#endif
