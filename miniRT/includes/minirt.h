/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:31:35 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:31:39 by jinukim          ###   ########.fr       */
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

# define SP 0
# define PL 1
# define SQ 2
# define CY 3
# define TR 4
# define CU 5
# define PY 6

# define BG_COLOR 0x000000
# define KEY_PRESS 2

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "vector.h"
# include "struct.h"
# include "color.h"
# include "utils.h"
# include "parsing.h"
# include "element.h"
# include "object.h"
# include "images.h"

int		g_x;
int		g_y;
void	errmsg(t_scene *sn, char *str);
int		key_handle(int keycode);

#endif
