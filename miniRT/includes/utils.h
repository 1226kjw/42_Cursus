/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:29:12 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:29:22 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

double	next_atof(char *str, int *i);
int		next_atoi(char *str, int *i);
t_v3	ft_atov(char *str, int *i);
int		ft_atoc(char *str, int *i);
int		color_combine(int a, int b);

#endif
