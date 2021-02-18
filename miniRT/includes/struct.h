/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:30:21 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 15:13:49 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minirt.h"

typedef struct	s_light
{
	t_v3	o;
	double	inten;
	int		color;
}				t_light;

typedef struct	s_sp
{
	t_v3	o;
	double	r;
	int		color;
}				t_sp;

typedef struct	s_pl
{
	t_v3	o;
	t_v3	n;
	int		color;
}				t_pl;

typedef struct	s_sq
{
	t_v3	o;
	t_v3	n;
	double	d;
	int		color;
	t_v3	hor;
	t_v3	ver;
}				t_sq;

typedef struct	s_cy
{
	t_v3	o;
	t_v3	d;
	double	r;
	double	h;
	int		color;
}				t_cy;

typedef struct	s_tr
{
	t_v3	a;
	t_v3	b;
	t_v3	c;
	int		color;
}				t_tr;

typedef struct	s_cu
{
	t_v3	o;
	t_v3	n;
	double	d;
	int		color;
}				t_cu;

typedef struct	s_py
{
	t_v3	o;
	t_v3	n;
	double	d;
	double	h;
	int		color;
}				t_py;

typedef struct	s_py_t
{
	t_v3	o;
	t_v3	n[2];
	double	d;
	double	h;
	int		color;
}				t_py_t;

typedef struct	s_co
{
	t_v3	o;
	t_v3	d;
	double	r;
	double	h;
	int		color;
}				t_co;

typedef struct	s_ci
{
	t_v3	o;
	t_v3	n;
	double	r;
	int		color;
}				t_ci;

typedef struct	s_cam
{
	t_v3	o;
	t_v3	d;
	int		fov;
	t_v3	hl;
	t_v3	hor;
	t_v3	ver;
	void	*img;
	char	*addr;
	int		bpp;
	int		lsize;
	int		endian;
}				t_cam;

typedef struct	s_scene
{
	int		x;
	int		y;
	t_light	*a_light;
	t_list	*cams;
	t_list	*basecam;
	t_list	*lights;
	t_list	*p_lights;
	t_list	*objs;
}				t_scene;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_scene	*sn;
}				t_data;

typedef struct	s_arg
{
	t_data	*mlx;
	t_scene	*sn;
	t_cam	*cam;
	int		id;
}				t_arg;

typedef struct	s_hit
{
	double	t;
	t_v3	p;
	int		type;
	void	*obj;
	t_v3	n;
	int		ocol;
	int		acol;
	int		dcol;
	int		scol;
	int		fcol;
}				t_hit;

#endif
