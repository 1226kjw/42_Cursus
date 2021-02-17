/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:10:47 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/17 23:53:07 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int type, void *content)
{
	t_list	*newnode;

	if (!(newnode = (t_list*)malloc(sizeof(t_list))))
		return (0);
	newnode->type = type;
	newnode->obj = content;
	newnode->next = 0;
	newnode->bef = 0;
	return (newnode);
}
