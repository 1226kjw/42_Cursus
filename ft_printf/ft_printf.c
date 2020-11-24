/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:55:08 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/24 21:09:01 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flagmng(t_fm *f, char *s, int *i)
{
	f->neg = 0;
	f->plus = 0;
	f->sp = 0;
	f->hash = 0;
	f->zero = 0;
	f->star = 0;
	f->acc = -2147483648;
	while (s[*i])
	{
		if (s[*i] == '-')
			f->neg = 1;
		else if (s[*i] == '+')
			f->plus = 1;
		else if (s[*i] == ' ')
			f->sp = 1;
		else if (s[*i] == '#')
			f->hash = 1;
		else if (s[*i] == '0')
			f->zero = 1;
		else if (s[*i] == '*')
			f->star = 1;
		else
			break ;
		++*i;
	}
}

static void	ft_newflag(va_list ap, t_fm *f, char *s, int *i)
{
	ft_flagmng(f, s, i);
	if (f->star)
		f->len = va_arg(ap, int);
	else if ((f->len = ft_atoi(s + *i)))
		while (s[++*i] && ft_isdigit(s[*i]))
			;
	if (s[*i] == '.')
	{
		if (s[++*i] == '*')
			f->acc = va_arg(ap, int);
		else if ((f->acc = ft_atoi(s + *i)) >= 0)
			while (s[*i] && ft_isdigit(s[*i]))
				++*i;
	}
	if (s[*i] == '0' || s[*i] == '*')
		++*i;
	if ((f->lh = 0) || s[*i] == 'l')
		f->lh = s[*i + 1] == 'l' ? 2 : 1;
	if (s[*i] == 'h')
		f->lh = s[*i + 1] == 'h' ? -2 : -1;
	*i += f->lh < 0 ? -f->lh : f->lh;
	f->t = s[*i];
	if ((f->len < 0) && (f->len = -f->len))
		f->neg = 1;
}

static int	ft_handle_for(va_list ap, char *s, int *i, int *n)
{
	t_fm		flag;

	++*i;
	ft_newflag(ap, &flag, s, i);
	if (flag.t == '%' || flag.t == 'o')
		*n += flag.t == '%' ? ft_printpct(flag) : ft_printf_o(ap, flag);
	else if (flag.t == 'c' || flag.t == 's')
		*n += flag.t == 'c' ? ft_printf_c(ap, flag) : ft_printf_s(ap, flag);
	else if (flag.t == 'p' || flag.t == 'd')
		*n += flag.t == 'p' ? ft_printf_p(ap, flag) : ft_printf_d(ap, flag);
	else if (flag.t == 'i' || flag.t == 'u')
		*n += flag.t == 'i' ? ft_printf_d(ap, flag) : ft_printf_u(ap, flag);
	else if (flag.t == 'x' || flag.t == 'X')
		*n += flag.t == 'x' ? ft_printf_x(ap, flag) : ft_printfxx(ap, flag);
	else if (flag.t == 'n' || flag.t == 'f')
		*n += flag.t == 'n' ? ft_printf_n(ap, flag, n) : ft_printf_f(ap, flag);
	else if (flag.t == 'e')
		*n += ft_printf_e(ap, flag);
	else
		return (-1);
	return (0);
}

static int	ft_handle_esc(char *s, int *i, int *n)
{
	char		c;

	if (s[*i] == 'a' || s[*i] == 'b')
		c = s[*i] == 'a' ? '\a' : '\b';
	else if (s[*i] == 'f' || s[*i] == 'n')
		c = s[*i] == 'f' ? '\f' : '\n';
	else if (s[*i] == 'r' || s[*i] == 't')
		c = s[*i] == 'r' ? '\r' : '\t';
	else if (s[*i] == 'v' || s[*i] == '\\')
		c = s[*i] == 'v' ? '\v' : '\\';
	else
		return (-1);
	write(1, &c, 1);
	(*n)++;
	return (0);
}

int			ft_printf(char *str, ...)
{
	va_list		ap;
	int			i;
	int			n;
	int			res;

	i = -1;
	n = 0;
	res = 0;
	va_start(ap, str);
	while (!res && str[++i])
		if (str[i] == '%')
			res = ft_handle_for(ap, str, &i, &n);
		else if (str[i] == '\\')
			res = ft_handle_esc(str, &i, &n);
		else
		{
			n++;
			write(1, &str[i], 1);
		}
	va_end(ap);
	return (res == -1 ? -1 : n);
}
