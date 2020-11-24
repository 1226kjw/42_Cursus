/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:53:46 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/20 22:40:03 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(va_list ap, t_fm f)
{
	char	c;
	int		n;

	n = 0;
	c = (char)va_arg(ap, int);
	if (f.neg)
		write(1, &c, 1);
	while (++n < f.len)
		write(1, f.zero == 1 && !f.neg ? "0" : " ", 1);
	if (!f.neg)
		write(1, &c, 1);
	return (n);
}
