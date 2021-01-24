/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:47:13 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/24 18:38:28 by jinukim          ###   ########.fr       */
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
# include "struct.h"
# include "utils.h"
# include "vector.h"
# include "parsing.h"
# include "get_next_line.h"
# include "intersect.h"

void			print_err_exit(int n);
int				make_image(t_data *data, t_scene *sd);
#endif
