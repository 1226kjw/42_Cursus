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

void	ft_lst_merge(t_list **org, t_list *new)
{
	if (!*org)
		*org = new;
	else
	{
		(*org)->bef->next = new;
		new->bef->next = (*org);
		t_list	*tmp = new->bef;
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

int		ft_lstsorted(t_list *lst)
{
	int		n;
	t_list	*tmp;

	n = lst->n;
	tmp = lst->next;
	while (tmp != lst)
	{
		if (n >= tmp->n)
			return (0);
		n = tmp->n;
		tmp = tmp->next;
	}
	return (1);
}

int		ft_lstiseq(t_list *l1, t_list *l2)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = l1;
	tmp2 = l2;
	if (!tmp1 && !tmp2)
		return (1);
	else if (!tmp1 || !tmp2)
		return (0);
	while (1)
	{
		if (tmp1->n != tmp2->n)
			return (0);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		if (tmp1 == l1)
			break ;
	}
	return (1);
}
