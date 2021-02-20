/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:31:35 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:11:53 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>

# define EPSILON 0.0001
# define SCALE 0.1
# define ANGLE M_PI / 12
# define NSCALE 5
# define AMP 1
# define RSCALE 5/7.0

# define SP 0
# define PL 1
# define SQ 2
# define CY 3
# define TR 4
# define CI 5
# define CO 6
# define CU 7
# define PY 8

# define BG_COLOR 0x000000

# define KEYPRESS 2
# define BUTTONPRESS 4
# define DESTROYNOT 17

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define Q_KEY 12
# define E_KEY 14
# define R_KEY 15
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define NUM1 83
# define NUM2 84
# define NUM3 85
# define NUM4 86
# define NUM5 87
# define NUM6 88
# define NUM7 89
# define NUM8 91
# define NUM9 92

# define BUT1_KEY 1

# include "../minilibx_mms/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "vector.h"
# include "color.h"
# include "struct.h"
# include "utils.h"
# include "parsing.h"
# include "element.h"
# include "object.h"
# include "images.h"

int		g_x;
int		g_y;
int		g_filter;
double	g_cb;
double	g_cr;
void	errmsg(t_scene *sn, char *str);
int		key_handle(int keycode, t_data *mlx);
int		button_handle(int button, int x, int y, t_data *mlx);
int		close_program(t_data *mlx);

#endif
