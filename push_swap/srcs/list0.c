#include "list.h"

t_list	*ft_lstnew(int n)
{
	t_list	*newlst;

	newlst = (t_list *)malloc(sizeof(t_list));
	if (!newlst)
		exit(-1);
	newlst->n = n;
	newlst->next = newlst;
	newlst->bef = newlst;
	return (newlst);
}

void	ft_lst_merge(t_list **org, t_list *new)
{
	t_list	*tmp;

	if (!*org)
		*org = new;
	else
	{
		(*org)->bef->next = new;
		new->bef->next = (*org);
		tmp = new->bef;
		new->bef = (*org)->bef;
		(*org)->bef = tmp;
		*org = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->bef = new;
	}
	else
	{
		new->bef = (*lst)->bef;
		(*lst)->bef->next = new;
		new->next = *lst;
		(*lst)->bef = new;
		(*lst) = new;
	}
}

void	ft_lstadd_last(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		(*lst)->bef->next = new;
		new->bef = (*lst)->bef;
		new->next = *lst;
		(*lst)->bef = new;
	}
}
