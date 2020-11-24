/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 03:07:53 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/27 05:18:07 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			exceptionmng(char *buf, t_fl u, t_fm *f, int *n)
{
	int					i;

	i = 0;
	f->zero = 0;
	if ((u.i & 0xfffffffffffff) == 0)
		ft_strcpy(buf, "inf");
	else
	{
		i = 1;
		f->sp = 0;
		f->plus = 0;
		ft_strcpy(buf, "nan");
	}
	*n = 3;
	return (i);
}

double		ft_floatmod(double x, double *ip)
{
	int					exp;
	unsigned long long	bm;
	t_fl				u;

	u.x = x;
	exp = (u.i >> 52 & 0x7ff) - 1023;
	if (exp >= 52)
	{
		*ip = u.x;
		return (0.0);
	}
	if (exp < 0)
	{
		*ip = 0.0;
		return (u.x);
	}
	bm = 0x000fffffffffffff >> exp;
	if ((u.i & bm) == 0)
	{
		*ip = x;
		return (0.0);
	}
	u.i &= ~bm;
	*ip = u.x;
	return (x - u.x);
}

int			ft_carry(char *buf, int last, double fpart)
{
	double			ipart;
	int				i;
	int				flag;

	flag = 0;
	fpart = ft_floatmod(fpart * 10, &ipart);
	if (ipart < 5.0)
		return (0);
	i = last;
	while (i >= 0 && (buf[i] == '9' || buf[i] == '.'))
		i--;
	if (i < 0)
	{
		while (++i <= last + 1)
			buf[last + 2 - i] = buf[last + 1 - i];
		buf[0] = '1';
		i = 1;
		flag = 1;
	}
	i--;
	while (buf[++i])
		if (buf[i] != '.')
			buf[i] = buf[i] == '9' ? '0' : buf[i] + 1;
	return (flag);
}

void		printsign(int *n, t_fm f, int m)
{
	if (m)
		write(1, "-", 1);
	else if (f.plus)
		write(1, "+", 1);
	else if (f.sp)
		write(1, " ", 1);
	else
		return ;
	++*n;
}

void		applynprint(char *str, int *n, t_fm f, int m)
{
	int				i;

	i = -1;
	*n = *n + (m || f.plus || f.sp) < f.len ? f.len :
		*n + (m || f.plus || f.sp);
	if (!f.neg)
	{
		if (f.zero)
			printsign(&i, f, m);
		while (*n - ++i > (int)ft_strlen(str)
				+ (!f.zero && (m || f.plus || f.sp)))
			write(1, f.zero ? "0" : " ", 1);
		if (!f.zero)
			printsign(&i, f, m);
		ft_putstr_fd(str, 1);
	}
	else
	{
		printsign(&i, f, m);
		ft_putstr_fd(str, 1);
		while (++i + (int)ft_strlen(str) < *n)
			write(1, " ", 1);
	}
}
