/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:53:25 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/25 16:03:44 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

double	ft_atolf(char *str)
{
	int		i;
	int		scale;
	double	ret;
	int		sign;

	sign = 1;
	i = 0;
	scale = 0;
	ret = 0.0;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : 1;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.'))
	{
		if (str[i] == '.')
		{
			scale = i++;
			continue ;
		}
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	if (scale)
		while (--i - scale > 0)
			ret /= 10.0;
	return (sign * ret);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}
