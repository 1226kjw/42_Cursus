/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:31:35 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 20:50:34 by jinukim          ###   ########.fr       */
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

# define EPSILON 0.00001
# define SCALE 0.5

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
# define ESC 53
# define LEFT 123
# define RIGHT 124

# define BUT1_KEY 1

# include "mlx.h"
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
void	errmsg(t_scene *sn, char *str);
int		key_handle(int keycode, t_data *mlx);
int		button_handle(int button, int x, int y, t_data *mlx);
int		close_program(t_data *mlx);

#endif
