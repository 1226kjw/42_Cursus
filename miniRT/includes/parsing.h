/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:24:38 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/22 18:13:19 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

int		parsing(int fd, t_scene *sd);
int		parsing_r(char *line, t_scene *sd);
int		parsing_c(char *line, t_scene *sd);
int		parsing_sp(char *line, t_scene *sd);

#endif
