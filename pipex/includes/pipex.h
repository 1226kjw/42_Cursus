/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:43:35 by jinukim           #+#    #+#             */
/*   Updated: 2021/06/28 17:55:41 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <sys/stat.h>

# include "utils.h"
# include "redirect.h"

# ifndef BONUS
#  define BONUS 0
# endif

# define READ 0
# define WRITE 1

#endif
