#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspdigit(char *str);
int		ft_atoi(char *str, int *i);
void	err_msg(char *str);
char	*ft_strdup(const char *str);
int     ter_tmp(int cond, int a, int b);
void	*ft_memcpy(void *dst, const void *src, int n);

#endif
