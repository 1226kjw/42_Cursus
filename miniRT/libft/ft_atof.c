/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:40:41 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 00:41:05 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	int		i;
	int		scale;
	double	ret;
	int		sign;

	i = 0;
	sign = 1;
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
