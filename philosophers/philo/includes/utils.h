#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

long	my_gettime(long bef);
void	err_msg(char *str);
int		ft_isdigit(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

#endif
