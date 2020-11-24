/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:40:15 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/20 22:40:44 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		putexp(char *buf, int last, int scale, int *n)
{
	buf[last] = 'e';
	buf[last + 1] = scale < 0 ? '-' : '+';
	*n += 2;
	scale *= scale < 0 ? -1 : 1;
	if (scale >= 100)
	{
		buf[last + 2] = scale / 100 + '0';
		buf[last + 3] = (scale / 10) % 10 + '0';
		buf[last + 4] = scale % 10 + '0';
		buf[last + 5] = 0;
		*n += 3;
	}
	else
	{
		buf[last + 2] = scale / 10 + '0';
		buf[last + 3] = scale % 10 + '0';
		buf[last + 4] = 0;
		*n += 2;
	}
}

static void		makebuf(char *buf, t_fl u, t_fm f, int *n)
{
	double			fpart;
	double			ipart;
	int				i;
	int				j;

	i = FBUFSIZE;
	fpart = ft_floatmod(u.x, &ipart);
	while (i == FBUFSIZE || ipart)
		buf[--i] = (int)(10 * (ft_floatmod(ipart / 10, &ipart) + 0.03)) + '0';
	j = 0;
	while (i < FBUFSIZE)
		buf[j++] = buf[i++];
	i = 0;
	buf[j] = f.acc == 0 && !f.hash ? 0 : '.';
	while (i++ < f.acc)
	{
		fpart = ft_floatmod(fpart * 10, &ipart);
		buf[++j] = (int)(ipart + 0.01) + '0';
	}
	buf[j + 1] = 0;
	*n = ft_strlen(buf);
	*n += ft_carry(buf, buf[j] == 0 ? j - 1 : j, fpart);
}

static void		makebuf_e(char *buf, t_fl u, t_fm f, int *n)
{
	int			scale;

	scale = 0;
	while (u.x >= 10.0)
	{
		scale++;
		u.x /= 10.0;
	}
	while (u.x < 1.0)
	{
		scale--;
		u.x *= 10.0;
	}
	makebuf(buf, u, f, n);
	if (ft_atoi(buf) >= 10.0)
	{
		buf[--*n] = 0;
		scale++;
		buf[2] = buf[1];
		buf[1] = !f.hash && !f.acc ? 0 : '.';
	}
	putexp(buf, (int)ft_strlen(buf), scale, n);
}

static void		makezero(char *buf, t_fm f, int *n)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	buf[i++] = '0';
	++*n;
	if (f.hash || f.acc)
	{
		buf[i++] = '.';
		++*n;
	}
	while (j++ < f.acc)
	{
		buf[i++] = '0';
		++*n;
	}
	putexp(buf, i, 0, n);
}

int				ft_printf_e(va_list ap, t_fm f)
{
	char		buf[FBUFSIZE];
	int			sign;
	int			n;
	t_fl		u;

	n = 0;
	u.x = (double)va_arg(ap, double);
	sign = (int)(u.i >> 63);
	u.i &= 0x7fffffffffffffff;
	if (f.acc < 0)
		f.acc = 6;
	if ((u.i >> 52 & 0x7ff) == 0x7ff)
		sign = exceptionmng(buf, u, &f, &n) ? 0 : sign;
	else if (u.x == 0.0)
		makezero(buf, f, &n);
	else
		makebuf_e(buf, u, f, &n);
	applynprint(buf, &n, f, sign);
	return (n);
}
