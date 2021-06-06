#include "utils.h"

int		ft_isspdigit(char *str)
{
	int				i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t' && (str[i] < '0' || str[i] > '9'))
			return (0);
	return (1);
}

int		ft_atoi(char *str, int *i)
{
	long long int	ret;
	long long int	sign;

	sign = 1;
	ret = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		++*i;
	}
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
			break ;
		ret = ret * 10 + str[*i] - '0';
		++*i;
	}
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		++*i;
	return (ret * sign);
}

void	err_msg(char *str)
{
	int				i;

	i = -1;
	while (str[++i])
		;
	write(2, str, i);
}
