/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:58:08 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 01:25:11 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern int	g_x;
extern int	g_y;

int			parsing_r(char *buf, t_scene *sn)
{
	int		i;

	i = 1;
	g_x = next_atoi(buf, &i);
	g_y = next_atoi(buf, &i);
	while (buf[i] && ft_isspace(buf[i]))
		i++;
	if (!g_x || !g_y)
		errmsg(sn, "res cannot be 0(18)");
	if (buf[i])
		errmsg(sn, "unexpected character(19)");
	return (0);
}

int			parsing_a(char *buf, t_scene *sn)
{
	int		i;
	t_light	*am;

	i = 1;
	if (sn->a_light)
		errmsg(sn, "dup ambient light(20)");
	am = (t_light*)ft_calloc(1, sizeof(t_light));
	am->o = vset(0, 0, 0);
	am->inten = next_atof(buf, &i);
	am->color = ft_atoc(buf, &i);
	sn->a_light = am;
	if (buf[i])
		errmsg(sn, "unexpected character(21)");
	return (0);
}

int			parsing_c(char *buf, t_scene *sn)
{
	int		i;
	t_v3	o;
	t_v3	d;
	int		fov;

	i = 1;
	o = ft_atov(buf, &i);
	d = ft_atov(buf, &i);
	fov = next_atoi(buf, &i);
	if (!d.x && !d.y && !d.z)
		errmsg(sn, "direction vector cannot be null vector");
	if (fov <= 0 || fov >= 180)
		errmsg(sn, "vaild fov : (0, 180)");
	ft_lstadd_back(&(sn->cams), ft_lstnew(0, newcam(o, d, fov)));
	return (0);
}

int			parsing_l(char *buf, t_scene *sn)
{
	int		i;
	t_v3	o;
	double	inten;
	int		color;

	i = 1;
	o = ft_atov(buf, &i);
	inten = next_atof(buf, &i);
	color = ft_atoc(buf, &i);
	if (inten < 0.0 || inten > 1.0)
		errmsg(sn, "valid intensity : [0, 1]");
	ft_lstadd_back(&(sn->lights), ft_lstnew(0, newlight(o, inten, color)));
	return (0);
}

int			parsing_p(char *buf, t_scene *sn)
{
	int		i;
	t_v3	o;
	double	inten;
	int		color;

	i = 1;
	o = ft_atov(buf, &i);
	if (!o.x && !o.y && !o.z)
		errmsg(sn, "direction vector cannot be null vector(p_light)");
	inten = next_atof(buf, &i);
	color = ft_atoc(buf, &i);
	if (inten < 0.0 || inten > 1.0)
		errmsg(sn, "valid intensity : [0, 1]");
	ft_lstadd_back(&(sn->p_lights), ft_lstnew(0, newlight(o, inten, color)));
	return (0);
}
