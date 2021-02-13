/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:31:00 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:31:13 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

int		parsing(int fd, t_scene *sn);
int		line_parsing(char *line, t_scene *sd);
int		parsing_r(char *buf, t_scene *sd);
int		parsing_a(char *buf, t_scene *sd);
int		parsing_c(char *buf, t_scene *sd);
int		parsing_l(char *buf, t_scene *sd);
int		parsing_sp(char *buf, t_scene *sd);
int		parsing_pl(char *buf, t_scene *sd);
int		parsing_sq(char *buf, t_scene *sd);
int		parsing_cy(char *buf, t_scene *sd);
int		parsing_tr(char *buf, t_scene *sd);

#endif
