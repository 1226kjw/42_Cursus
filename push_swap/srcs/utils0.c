#include "utils.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				ret;
	int				idx;

	ret = 0;
	idx = 0;
	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
		return (-1);
	else if (s1 && !s2)
		return (1);
	while (!ret && (s1[idx] || s2[idx]))
	{
		ret = (unsigned char)s1[idx] - (unsigned char)s2[idx];
		idx++;
	}
	return (ret);
}

int	ft_isspdigit(char *str)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] >= '0' && str[i + 1] <= '9')
			&& (i == 0 || str[i - 1] == ' '))
			continue ;
		else if (str[i] != ' ' && str[i] != '\t'
			&& (str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		;
	return (i);
}

int	ft_atoi(char *str, int *i)
{
	long long int	ret;
	long long int	sign;

	sign = 1;
	ret = 0;
	if (ft_strlen(str) > 12)
		err_msg("Error\n");
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
	if (ret * sign < -2147483648LL || ret * sign > 2147483647)
		err_msg("Error\n");
	return (ret * sign);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int		i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}
