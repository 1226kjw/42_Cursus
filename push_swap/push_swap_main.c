#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void	print_inst(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (str[i] == 0)
			write(1, "sa\n", 3);
		else if (str[i] == 1)
			write(1, "sb\n", 3);
		else if (str[i] == 2)
			write(1, "ss\n", 3);
		else if (str[i] == 3)
			write(1, "pa\n", 3);
		else if (str[i] == 4)
			write(1, "pb\n", 3);
		else if (str[i] == 5)
			write(1, "ra\n", 3);
		else if (str[i] == 6)
			write(1, "rb\n", 3);
		else if (str[i] == 7)
			write(1, "rr\n", 3);
		else if (str[i] == 8)
			write(1, "rra\n", 4);
		else if (str[i] == 9)
			write(1, "rrb\n", 4);
		else if (str[i] == 10)
			write(1, "rrr\n", 4);
		i++;
	}
}

int		comp(const void *a, const void *b)
{
	int		*na;
	int		*nb;

	na = (int*)a;
	nb = (int*)b;
	if (*na == *nb)
		err_msg("Error\n");
	return (*na - *nb);
}

void	pre_pro(t_board *bd, int *ans)
{
	int		i;
	t_list	*tmp;

	tmp = bd->a;
	while (1)
	{
		i = -1;
		while (tmp->n != ans[++i])
			;
		tmp->n = i;
		tmp = tmp->next;
		if (tmp == bd->a)
			break ;
	}
	free(ans);
}

extern int		max_heap;

t_board	*astar(t_board *bd, int direct)
{
	t_priq	*root;
	t_node	node;
	t_board	*ret;

	root = (t_priq*)malloc(sizeof(t_priq));
	root->count = 0;
	node.g = 0;
	node.f = calc_h(bd);
	node.hist = strdup("");
	node.bd = board_cp(bd);
	priq_push(root, node);
	while (root->count)
	{
		t_node now = priq_pop(root);
		if (calc_h(now.bd) == 0)
		{
			print_inst(now.hist, now.g);
			free(now.hist);
			ret = now.bd;
			break;
		}
		for (int i=0;i<11;i++)
		{
			if (!direct && (5 <= i && i <= 10))
				continue;
			t_node t = node_init(now, i);
			if (t.bd)
				priq_push(root, t);
		}
		free(now.hist);
		board_clear(now.bd);
	}
	//printf("max heap : %d\n", max_heap);
	//max_heap = 0;
	free(root);
	return (ret);
}

t_board	*newboard_only_a(t_board *bd, int count, int min)
{
	t_board		*nb;
	t_list		*cur;

	nb = (t_board*)malloc(sizeof(t_board));
	cur = bd->a;
	nb->a = 0;
	nb->b = 0;
	nb->na = count;
	nb->nb = 0;
	for(int i=0;i<count;i++)
	{
		ft_lstadd_last(&nb->a, ft_lstnew(cur->n - min));
		cur = cur->next;
	}
	return (nb);
}

void	board_merge(t_board *org, t_board *tmp, int count, int min)
{
	t_list	*cur_org;
	t_list	*cur_tmp;

	cur_org = org->a;
	cur_tmp = tmp->a;
	for(int i=0;i<count;i++)
	{
		cur_org->n = cur_tmp->n + min;
		cur_org = cur_org->next;
		cur_tmp = cur_tmp->next;
	}
	board_clear(tmp);
}

void	btoa(t_board *bd, int count, int min, int max);
void	atob(t_board *bd, int count, int min, int max)
{
	int		pivot;
	int		n_ra;
	int		n_pb;

	if (count <= 8)
	{
		t_board *newboard = newboard_only_a(bd, count, min);
		t_board *tmp = astar(newboard, 0);
		board_clear(newboard);
		board_merge(bd, tmp, count, min);
		return ;
	}
	pivot = (min + max) / 2;
	n_ra = 0;
	n_pb = 0;
	for(int i=0;i<count;i++)
	{
		if (bd->a->n > pivot)
		{
			board_ra(bd);
			printf("ra\n");
			n_ra++;
		}
		else
		{
			board_pb(bd);
			printf("pb\n");
			n_pb++;
		}
	}
	for(int i=0;i<n_ra;i++)
	{
		board_rra(bd);
		printf("rra\n");
	}
	atob(bd, n_ra, pivot + 1, max);
	btoa(bd, n_pb, min, pivot);
}

void	btoa(t_board *bd, int count, int min, int max)
{
	int		pivot;
	int		n_rb;
	int		n_pa;

	n_rb = 0;
	n_pa = 0;
	if (count == 1)
	{
		board_pa(bd);
		printf("pa\n");
		return ;
	}
	pivot = (min + max) / 2;
	for(int i=0;i<count;i++)
	{
		if (bd->b->n < pivot)
		{
			board_rb(bd);
			printf("rb\n");
			n_rb++;
		}
		else
		{
			board_pa(bd);
			printf("pa\n");
			n_pa++;
		}
	}
	for(int i=0;i<n_rb;i++)
	{
		board_rrb(bd);
		printf("rrb\n");
	}
	atob(bd, n_pa, pivot, max);
	btoa(bd, n_rb, min, pivot);
}

int		main(int argc, char **argv)
{
	t_board	*bd;
	int		*ans;
	int		i;

	setbuf(stdout, 0);
	bd = board_init(argc, argv);
	if (!bd)
		err_msg("Error\n");
	ans = (int*)malloc(sizeof(int) * bd->na);
	i = 0;
	while (i < bd->na)
	{
		ans[i] = bd->a->n;
		bd->a = bd->a->next;
		i++;
	}
	qsort(ans, bd->na, sizeof(int), comp);
	pre_pro(bd, ans);
	if (bd->na < 10)
		astar(bd, 1);
	else
		atob(bd, bd->na, 0, bd->na - 1);
}
