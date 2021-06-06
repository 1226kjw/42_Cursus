#include "list.h"

t_list	*ft_lstnew(int n)
{
	t_list	*newlst;

	if (!(newlst = (t_list*)malloc(sizeof(t_list))))
		exit(-1);
	newlst->n = n;
	newlst->next = newlst;
	newlst->bef = newlst;
	return (newlst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
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

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*org;

	i = 0;
	org = lst;
	while (org)
	{
		i++;
		org = org->next;
		if (org == lst)
			break;
	}
	return (i);
}

t_list	*ft_lstdel_front(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return 0;
	tmp = *lst;
	tmp->next->bef = tmp->bef;
	tmp->bef->next = tmp->next;
	if (tmp == tmp->next)
		*lst = 0;
	else
		*lst = tmp->next;
	tmp->bef = tmp;
	tmp->next = tmp;
	return (tmp);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = ft_lstsize(*lst);
	while (i > 0)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		i--;
	}
	*lst = 0;
}
