/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:37 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/20 22:42:56 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(va_list ap, t_fm f)
{
	char	*str;
	int		n;
	int		i;
	int		l;

	i = 0;
	n = 0;
	str = (char*)va_arg(ap, char*);
	str = str == 0 ? "(null)" : str;
	l = (int)ft_strlen(str);
	f.acc = f.acc < 0 ? l : f.acc;
	if (f.neg)
		while (str[i] && i < f.acc)
			write(1, &str[i++], 1);
	while (((l > f.acc ? f.acc : l) + n++ < f.len))
		write(1, (f.zero == 1 && !f.neg) ? "0" : " ", 1);
	if (!f.neg)
		while (str[i] && i < f.acc)
			write(1, &str[i++], 1);
	return (i > f.len ? i : f.len);
}
