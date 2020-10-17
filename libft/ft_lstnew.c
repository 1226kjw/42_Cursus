/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:10:47 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/01 20:44:58 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	if (!(newnode = (t_list*)malloc(sizeof(t_list))))
		return (0);
	newnode->content = content;
	newnode->next = 0;
	return (newnode);
}
