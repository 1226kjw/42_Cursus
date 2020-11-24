/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:40:15 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/20 22:41:12 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int				ft_printf_f(va_list ap, t_fm f)
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
	else
		makebuf(buf, u, f, &n);
	applynprint(buf, &n, f, sign);
	return (n);
}
