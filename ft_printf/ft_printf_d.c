/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:22:59 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/20 22:40:22 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long			pulldec(va_list ap, int lh)
{
	if (lh == -2)
		return ((long long)(char)va_arg(ap, int));
	else if (lh == -1)
		return ((long long)(short)va_arg(ap, int));
	else if (lh == 0)
		return ((long long)va_arg(ap, int));
	else if (lh == 1)
		return ((long long)va_arg(ap, long));
	else if (lh == 2)
		return ((long long)va_arg(ap, long long));
	return (0);
}

int							ft_printf_d(va_list ap, t_fm f)
{
	long long			x;
	unsigned long long	u;
	char				buf[MAX + 2];
	int					i;
	int					n;

	f.zero = f.acc < 0 ? f.zero : 0;
	n = 0;
	u = 0;
	x = pulldec(ap, f.lh);
	if (x < 0 && (buf[MAX + 1] = 1))
		u = -x;
	else if (!(buf[MAX + 1] = 0))
		u = x;
	i = MAX;
	buf[MAX] = 0;
	while (u || n < f.acc || (f.acc && n == 0))
	{
		buf[--i] = u % 10 + '0';
		u /= 10;
		n++;
	}
	applynprint(buf + i, &n, f, buf[MAX + 1]);
	return (n);
}
