/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:35:35 by jinukim           #+#    #+#             */
/*   Updated: 2020/11/24 21:09:07 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# ifndef FBUFSIZE
#  define FBUFSIZE 2048
# endif
# ifndef MAX
#  define MAX 2048
# endif

typedef struct	s_fm
{
	int			neg;
	int			plus;
	int			sp;
	int			hash;
	int			zero;
	int			star;
	int			len;
	int			acc;
	int			lh;
	char		t;
}				t_fm;
typedef union	u_fl
{
	double				x;
	unsigned long long	i;
}				t_fl;
int				ft_printf(char *str, ...);
int				ft_printpct(t_fm f);
int				ft_printf_c(va_list ap, t_fm f);
int				ft_printf_s(va_list ap, t_fm f);
int				ft_printf_p(va_list ap, t_fm f);
int				ft_printf_d(va_list ap, t_fm f);
int				ft_printf_u(va_list ap, t_fm f);
int				ft_printf_x(va_list ap, t_fm f);
int				ft_printfxx(va_list ap, t_fm f);
int				ft_printf_n(va_list ap, t_fm f, int *n);
int				ft_printf_f(va_list ap, t_fm f);
int				ft_printf_e(va_list ap, t_fm f);
int				ft_printf_o(va_list ap, t_fm f);
double			ft_floatmod(double x, double *ip);
int				ft_carry(char *buf, int last, double fpart);
void			applynprint(char *str, int *n, t_fm f, int m);
int				exceptionmng(char *buf, t_fl u, t_fm *f, int *n);

#endif
