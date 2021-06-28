/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipemng.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:56:12 by jinukim           #+#    #+#             */
/*   Updated: 2021/06/28 17:56:14 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEMNG_H
# define PIPEMNG_H

int		redirect_in(char *file);
int		redirect_out(char *file);
void	pipe_attach(int fd[2], int io);

#endif
