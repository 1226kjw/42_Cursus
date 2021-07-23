#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char	inst[65536];
int		c;

int		better;

void	write_inst(char *str, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		inst[c++] = str[i];
}

char	bef_inst(int i, int *j)
{
	while (--i >= 0 && inst[i] == -1)
		;
	if (i < 0)
		return (-1);
	*j = i;
	return (inst[i]);
}

int		set_ff(int a, int b)
{
	inst[a] = -1;
	inst[b] = -1;
	better -= 2;
	return (1);
}

int		set_fff(int a, int b, int c)
{
	inst[a] = -1;
	inst[b] = -1;
	inst[c] = -1;
	better -= 3;
	return (1);
}

int		comp_inst()
{
	int		flag;
	int		i;
	int		j;
	int		k;
	char	bef1;
	char	bef2;

	flag = 0;
	i = 0;
	while (++i < c)
	{
		if (inst[i] == -1)
			continue ;
		bef1 = bef_inst(i, &j);
		bef2 = bef_inst(j, &k);
		if (inst[i] == 0 && bef1 == 0)
			flag = set_ff(i, j);
		else if (inst[i] == 1 && bef1 == 1)
			flag = set_ff(i, j);
		else if (inst[i] == 2 && bef1 * bef2 == 0 && bef1 + bef2 == 1)
			flag = set_fff(i, j, j);
		else if (inst[i] == 3 && bef1 == 4)
			flag = set_ff(i, j);
		else if (inst[i] == 4 && bef1 == 3)
			flag = set_ff(i, j);
		else if (inst[i] == 5 && bef1 == 8)
			flag = set_ff(i, j);
		else if (inst[i] == 6 && bef1 == 9)
			flag = set_ff(i, j);
		else if (inst[i] == 8 && bef1 == 5)
			flag = set_ff(i, j);
		else if (inst[i] == 9 && bef1 == 6)
			flag = set_ff(i, j);
		if ((inst[i] == 0 && bef1 == 1) || (inst[i] == 1 && bef1 == 0))
		{
			flag = 1;
			inst[i] = 2;
			inst[j] = -1;
			better -= 1;
		}
		if ((inst[i] == 5 && bef1 == 6) || (inst[i] == 6 && bef1 == 5))
		{
			flag = 1;
			inst[i] = 7;
			inst[j] = -1;
			better -= 1;
		}
		if ((inst[i] == 8 && bef1 == 9) || (inst[i] == 9 && bef1 == 8))
		{
			flag = 1;
			inst[i] = 10;
			inst[j] = -1;
			better -= 1;
		}
	}
	return (flag);
}

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

t_board	*astar(t_board *bd, int direct, t_dp *dp)
{
	t_priq	*root;
	t_node	node;
	t_board	*ret;
	t_dp	*cur;

	if (dp)
	{
		cur = dp_pick(dp, bd, bd->na, bd->nb);
		if (cur->hist)
		{
			write_inst(cur->hist, cur->g);
			return board_cp(cur->bd);
		}
	}
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
			write_inst(now.hist, now.g);
			if (dp)
			{
				cur->hist = now.hist;
				cur->bd = board_cp(now.bd);
				cur->g = now.g;
			}
			ret = now.bd;
			break;
		}
		for (int i=0;i<=10;i++)
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
	max_heap = 0;
	//priq_free(root);
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

t_board	*newboard_only_b(t_board *bd, int count, int min)
{
	t_board		*nb;
	t_list		*cur;

	nb = (t_board*)malloc(sizeof(t_board));
	cur = bd->b;
	nb->a = 0;
	nb->b = 0;
	nb->na = 0;
	nb->nb = count;
	for(int i=0;i<count;i++)
	{
		ft_lstadd_last(&nb->b, ft_lstnew(cur->n - min));
		cur = cur->next;
	}
	return (nb);
}

void	board_merge_a(t_board *org, t_board *tmp, int count, int min)
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

void	board_merge_b(t_board *org, t_board *tmp, int count, int min)
{
	t_list	*cur;

	ft_lst_merge(&org->a, tmp->a);
	org->na += tmp->na;
	cur = org->a;
	for(int i=0;i<count;i++)
	{
		cur->n += min;
		cur = cur->next;
		free(ft_lstdel_front(&org->b));
	}
	org->nb -= count;
}

void	atob(t_board *bd, int count, int min, int max, t_dp **dp)
{
	int		pivot;
	int		n_ra;
	int		n_pb;

	if (count <= ASTAR_MAX)
	{
		t_board *newboard = newboard_only_a(bd, count, min);
		t_board *tmp = astar(newboard, 0, dp[0]);
		board_clear(newboard);
		board_merge_a(bd, tmp, count, min);
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
			write_inst("\x5", 1);
			n_ra++;
		}
		else
		{
			board_pb(bd);
			write_inst("\x4", 1);
			n_pb++;
		}
	}
	if (n_ra < bd->na / 2)
		for(int i=0;i<n_ra;i++)
		{
			board_rra(bd);
			write_inst("\x8", 1);
		}
	else
		for(int i=0; i < bd->na - n_ra;i++)
		{
			board_ra(bd);
			write_inst("\x5", 1);
		}
	atob(bd, n_ra, pivot + 1, max, dp);
	btoa(bd, n_pb, min, pivot, dp);
}

void	btoa(t_board *bd, int count, int min, int max, t_dp **dp)
{
	int		pivot;
	int		n_rb;
	int		n_pa;

	n_rb = 0;
	n_pa = 0;
	if (count <= ASTAR_MAX)
	{
		t_board *newboard = newboard_only_b(bd, count, min);
		t_board *tmp = astar(newboard, 0, dp[1]);
		board_clear(newboard);
		board_merge_b(bd, tmp, count, min);
		return ;
	}
	pivot = (min + max) / 2;
	for(int i=0;i<count;i++)
	{
		if (bd->b->n <= pivot)
		{
			board_rb(bd);
			write_inst("\x6", 1);
			n_rb++;
		}
		else
		{
			board_pa(bd);
			write_inst("\x3", 1);
			n_pa++;
		}
	}
	if (n_rb < bd->nb / 2)
		for(int i=0;i<n_rb;i++)
		{
			board_rrb(bd);
			write_inst("\x9", 1);
		}
	else
		for(int i=0;i<bd->nb - n_rb;i++)
		{
			board_rb(bd);
			write_inst("\x6", 1);
		}
	atob(bd, n_pa, pivot + 1, max, dp);
	btoa(bd, n_rb, min, pivot + 1, dp);
}

int		main(int argc, char **argv)
{
	t_board	*bd;
	int		*ans;
	int		i;
	t_dp	*dp[2];

	for(int i=0;i<65536;i++)
		inst[i] = -1;
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
	dp[0] = dp_init();
	dp[1] = dp_init();
	if (bd->na < 10)
		astar(bd, 1, 0);
	else
		atob(bd, bd->na, 0, bd->na - 1, dp);
	while (comp_inst())
		;
	print_inst(inst, c);
	board_clear(bd);
	dp_free(dp[0]);
	dp_free(dp[1]);
	printf("%d\n", better);
}
