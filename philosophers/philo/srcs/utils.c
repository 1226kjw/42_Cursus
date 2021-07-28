#include "utils.h"

void	err_msg(char *str)
{
	if (str)
		printf("%s", str);
	exit(-1);
}

int	ft_isdigit(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_atoi(char *str)
{
	long long int	ret;
	int				i;

	if (ft_strlen(str) > 12)
		err_msg("not in 'int' range.\n");
	i = -1;
	ret = 0;
	while (str[++i])
		ret = ret * 10 + str[i] - '0';
	if (ret < -2147483648LL || ret > 2147483647LL)
		err_msg("not in 'int' range.\n");
	return (ret);
}
