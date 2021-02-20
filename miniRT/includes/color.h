/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:41:23 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 01:04:28 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "minirt.h"

# define RED 0xff0000
# define ORANGE 0xff7f00
# define YELLOW 0xffff00
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define INDIGO 0x4b0082
# define VIOLET 0x9400d3

int		color_combine(int a, int b);
int		cred(int a);
int		cgreen(int a);
int		cblue(int a);
int		cset(int r, int g, int b);
int		cadd(int a, int b);
int		cmul(int a, double i);
int		ccom(int a, int b);
int		cfil(int a);
int		caverage(int a, int b, int c, int d);
int		crainbow(t_v3 p, t_v3 o);

#endif
