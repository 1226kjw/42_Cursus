/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:29:28 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/14 00:29:32 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "minirt.h"

t_cam	*newcam(t_v3 o, t_v3 d, int fov);
t_light	*newlight(t_v3 o, double inten, int color);

#endif
