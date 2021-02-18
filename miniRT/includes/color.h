/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:41:23 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/18 22:19:00 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "minirt.h"

int		color_combine(int a, int b);
int		cred(int a);
int		cgreen(int a);
int		cblue(int a);
int		cset(int r, int g, int b);
int		cadd(int a, int b);
int		cmul(int a, double i);
int		ccom(int a, int b);
int		cfil(int a);

#endif
