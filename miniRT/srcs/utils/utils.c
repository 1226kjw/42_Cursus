/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:37 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/20 18:00:19 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		next_atof(char *str, int *i)
{
	int		j;

	while (str[*i] && !ft_isdigit(str[*i]) && str[*i] != '-')
		++*i;
	j = *i;
	while (str[*i] && (ft_isdigit(str[*i]) || str[*i] == '-'))
		++*i;
	if (str[*i] == '.')
		++*i;
	while (str[*i] && ft_isdigit(str[*i]))
		++*i;
	return (ft_atof(str + j));
}

int			next_atoi(char *str, int *i)
{
	int		j;

	while (str[*i] && !ft_isdigit(str[*i]) && str[*i] != '-')
		++*i;
	j = *i;
	while (str[*i] && (ft_isdigit(str[*i]) || str[*i] == '-'))
		++*i;
	return (ft_atoi(str + j));
}

t_v3		ft_atov(char *str, int *i)
{
	t_v3	v;

	v.x = next_atof(str, i);
	if (str[*i] != ',')
		errmsg(0, "format error1");
	v.y = next_atof(str, i);
	if (str[*i] != ',')
		errmsg(0, "format error2");
	v.z = next_atof(str, i);
	if (str[*i] != 0 && !ft_isspace(str[*i]))
		errmsg(0, "unexpected character at vector");
	return (v);
}

int			ft_atoc(char *str, int *i)
{
	int		c[3];
	int		col;

	c[0] = next_atoi(str, i);
	if (str[*i] != ',')
		errmsg(0, "format error3");
	c[1] = next_atoi(str, i);
	if (str[*i] != ',')
		errmsg(0, "format error4");
	c[2] = next_atoi(str, i);
	if (str[*i] != 0 && !ft_isspace(str[*i]))
		errmsg(0, "unexpected character at color");
	if (c[0] < 0 || c[1] < 0 || c[2] < 0 ||
			c[0] > 255 || c[1] > 255 || c[2] > 255)
		errmsg(0, "valid rgb : [0, 255]");
	col = c[2];
	col |= (c[1] << 8);
	col |= (c[0] << 16);
	return (col);
}

int			issplit(t_v3 a, t_v3 b, t_v3 p, t_v3 q)
{
	t_v3	u;
	t_v3	v;

	u = vcross(vsub(b, a), vsub(p, a));
	v = vcross(vsub(b, a), vsub(q, a));
	if (vinner(u, v) <= 0)
		return (1);
	return (0);
}
