/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:00:25 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/23 01:18:24 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_n(va_list ap, t_fm f, int *n)
{
	if (f.lh == -2)
		*(char*)va_arg(ap, char*) = *n;
	else if (f.lh == -1)
		*(short*)va_arg(ap, short*) = *n;
	else if (f.lh == 0)
		*(int*)va_arg(ap, int*) = *n;
	else if (f.lh == 1)
		*(long*)va_arg(ap, long*) = *n;
	else if (f.lh == 2)
		*(long long*)va_arg(ap, long long*) = *n;
	else
		*n = -1;
	return (0);
}
