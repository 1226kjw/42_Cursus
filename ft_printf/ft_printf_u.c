/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:22:59 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/20 22:43:12 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	pulldec(va_list ap, int lh)
{
	if (lh == -2)
		return ((unsigned long long)(unsigned char)va_arg(ap, unsigned int));
	else if (lh == -1)
		return ((unsigned long long)(unsigned short)va_arg(ap, unsigned int));
	else if (lh == 0)
		return ((unsigned long long)va_arg(ap, unsigned int));
	else if (lh == 1)
		return ((unsigned long long)va_arg(ap, unsigned long));
	else if (lh == 2)
		return ((unsigned long long)va_arg(ap, unsigned long long));
	return (0);
}

static void					u_applynprint(char *str, int *n, t_fm f)
{
	int					i;

	i = (f.hash && (f.zero || f.neg)) * 2 - 1;
	*n = *n + f.hash * 2 < f.len ? f.len : *n + f.hash * 2;
	if (f.hash && (f.zero || f.neg))
		write(1, "0x", 2);
	if (!f.neg)
	{
		while (*n - ++i > (int)ft_strlen(str) + 2 * (!f.zero * f.hash))
			write(1, f.zero == 1 ? "0" : " ", 1);
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_putstr_fd(str, 1);
		while (++i + (int)ft_strlen(str) < *n)
			write(1, " ", 1);
	}
}

int							ft_printf_u(va_list ap, t_fm f)
{
	unsigned long long	x;
	char				buf[MAX + 1];
	int					i;
	int					n;

	f.zero = f.acc < 0 ? f.zero : 0;
	n = 0;
	x = pulldec(ap, f.lh);
	i = MAX;
	buf[MAX] = 0;
	if (x == 0 && f.t != 'p')
		f.hash = 0;
	while (x || n < f.acc || (f.acc && n == 0))
	{
		buf[--i] = x % 10 + '0';
		x /= 10;
		n++;
	}
	u_applynprint(buf + i, &n, f);
	return (n);
}
