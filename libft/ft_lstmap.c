/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 22:16:29 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/02 16:44:56 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcur;

	if (!lst)
		return (0);
	newlst = ft_lstnew(f(lst->content));
	newcur = newlst;
	lst = lst->next;
	while (lst)
	{
		if (!(newcur->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		newcur = newcur->next;
		lst = lst->next;
	}
	return (newlst);
}
