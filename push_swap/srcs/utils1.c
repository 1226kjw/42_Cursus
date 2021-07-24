#include "utils.h"

void	err_msg(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	write(2, str, i);
	exit(1);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*arr;

	i = -1;
	while (str[++i])
		;
	arr = (char *)malloc((i + 1) * sizeof(char));
	if (arr == 0)
		return ((char *)0);
	arr[i] = 0;
	while (--i >= 0)
		arr[i] = str[i];
	return (arr);
}

int	ter_tmp(int cond, int a, int b)
{
	if (cond)
		return (a);
	else
		return (b);
}

int	dist(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
