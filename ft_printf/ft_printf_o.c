/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:22:59 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/20 22:42:22 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	pulloct(va_list ap, int lh)
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

static void					o_applynprint(char *str, int *n, t_fm f)
{
	int					i;

	i = (f.hash && (f.zero || f.neg)) - 1;
	*n = *n + f.hash < f.len ? f.len : *n + f.hash;
	if (f.hash && (f.zero || f.neg))
		write(1, "0", str[0] == '0' ? 0 : 1);
	if (!f.neg)
	{
		while (*n - ++i > (int)ft_strlen(str) + (!f.zero * f.hash))
			write(1, f.zero == 1 ? "0" : " ", 1);
		if (!f.zero && f.hash)
			write(1, "0", 1);
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_putstr_fd(str, 1);
		while (++i + (int)ft_strlen(str) < *n)
			write(1, " ", 1);
	}
}

int							ft_printf_o(va_list ap, t_fm f)
{
	unsigned long long	x;
	char				buf[MAX + 1];
	int					i;
	int					n;

	f.zero = f.acc < 0 ? f.zero : 0;
	n = 0;
	x = pulloct(ap, f.lh);
	i = MAX;
	buf[MAX] = 0;
	while (x || n < f.acc || (f.acc && n == 0))
	{
		buf[--i] = x % 8 + '0';
		x /= 8;
		n++;
	}
	o_applynprint(buf + i, &n, f);
	return (n);
}
