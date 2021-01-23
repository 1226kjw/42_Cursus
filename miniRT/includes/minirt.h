/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:47:13 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/22 22:20:43 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef MAXCAM
#  define MAXCAM 32
# endif
# ifndef MAXLIGHT
#  define MAXLIGHT 64
# endif
# ifndef MAXSPHERE
#  define MAXSPHERE 64
# endif


# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <unistd.h>

# include "../minilibx_mms/mlx.h"
# include "vector.h"
# include "parsing.h"
# include "get_next_line.h"

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			bytes_per_line;
	int			endian;
}				t_data;

typedef struct	s_cam
{
	t_vec		pos;
	t_vec		v;
	int			fov;
}				t_cam;

typedef struct	s_light
{
	t_vec		pos;
	t_vec		color;
	double	brightness;
}				t_light;

typedef struct	s_sphere
{
	t_vec		pos;
	t_vec		color;
	double	r;
}				t_sphere;

typedef struct	s_scene
{
	int			x;
	int			y;
	t_vec		hor;
	t_vec		ver;
	int			ncam;
	int			nlight;
	int			nsphere;
	t_cam		cam[MAXCAM];
	t_light		light[MAXLIGHT];
	t_sphere	sphere[MAXSPHERE];
}				t_scene

void			print_err_exit(int n);

#endif
