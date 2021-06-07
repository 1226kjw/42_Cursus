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
	i = -1;
	while (++i < bd->na + bd->nb)
		ans[i] = i;
}

int		main(int argc, char **argv)
{
	t_board	*bd;
	int		*ans;
	int		i;
	t_priq	*root;
	t_node	node;

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
	root = (t_priq*)malloc(sizeof(t_priq));
	root->count = 0;

	node.g = 0;
	node.f = calc_h(bd, ans);
	node.hist = strdup("");
	node.bd = board_cp(bd);
	priq_push(root, node);
	while (root->count)
	{
		t_node now = priq_pop(root);
		if (calc_h(now.bd, ans) == 0)
		{
			print_inst(now.hist, now.g);
			break;
		}
		for (int i=0;i<11;i++)
			priq_push(root, node_init(now, i, ans));
		free(now.hist);
		board_clear(now.bd);
	}
}
