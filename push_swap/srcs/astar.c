# include "astar.h"

int		dist(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}

int		ispossible(int inst, t_board *bd, int g, char *h)
{
	int		a;
	int		b;

	a = bd->na;
	b = bd->nb;
	g--;
	if (inst == 0)
		return ((a > 1) && (g < 0 || (h[g] != 0 && h[g] != 1 && h[g] != 2)));
	else if (inst == 1)
		return ((b > 1) && (g < 0 || (h[g] != 0 && h[g] != 1 && h[g] != 2)));
	else if (inst == 2)
		return ((a > 1 && b > 1) && (g < 0 || h[g] != 2));
	else if (inst == 3)
		return ((b > 0) && (g < 0 || h[g] != 4));
	else if (inst == 4)
		return ((a > 0) && (g < 0 || h[g] != 3));
	else if (inst == 5)
		return ((a > 2) && (g < 0 || (h[g] != 6 && h[g] != 8 && h[g] != 10)));
	else if (inst == 6)
		return ((b > 2) && (g < 0 || (h[g] != 5 && h[g] != 9 && h[g] != 10)));
	else if (inst == 7)
		return ((a > 2 && b > 2) && (g < 0 || h[g] != 10));
	else if (inst == 8)
		return ((a > 2) && (g < 0 || (h[g] != 5 && h[g] != 7 && h[g] != 9)));
	else if (inst == 9)
		return ((b > 2) && (g < 0 || (h[g] != 6 && h[g] != 7 && h[g] != 8)));
	else if (inst == 10)
		return ((a > 2 && b > 2) && (g < 0 || h[g] != 7));
	return 0;
}

t_node	node_init(t_node now, int inst)
{
	t_node	ret;

	ret.bd = board_cp(now.bd);
	if (inst == 0 && ispossible(inst, ret. bd, now.g, now.hist))
		board_sa(ret.bd);
	else if (inst == 1 && ispossible(inst, ret. bd, now.g, now.hist))
		board_sb(ret.bd);
	else if (inst == 2 && ispossible(inst, ret. bd, now.g, now.hist))
		board_ss(ret.bd);
	else if (inst == 3 && ispossible(inst, ret. bd, now.g, now.hist))
		board_pa(ret.bd);
	else if (inst == 4 && ispossible(inst, ret. bd, now.g, now.hist))
		board_pb(ret.bd);
	else if (inst == 5 && ispossible(inst, ret. bd, now.g, now.hist))
		board_ra(ret.bd);
	else if (inst == 6 && ispossible(inst, ret. bd, now.g, now.hist))
		board_rb(ret.bd);
	else if (inst == 7 && ispossible(inst, ret. bd, now.g, now.hist))
		board_rr(ret.bd);
	else if (inst == 8 && ispossible(inst, ret. bd, now.g, now.hist))
		board_rra(ret.bd);
	else if (inst == 9 && ispossible(inst, ret. bd, now.g, now.hist))
		board_rrb(ret.bd);
	else if (inst == 10 && ispossible(inst, ret. bd, now.g, now.hist))
		board_rrr(ret.bd);
	else
	{
		board_clear(ret.bd);
		ret.bd = 0;
		return ret;
	}
	ret.g = now.g + 1;
	ret.f = ret.g + calc_h(ret.bd);
	ret.hist = (char*)malloc(now.g + 1);
	memcpy(ret.hist, now.hist, now.g);
	ret.hist[now.g] = (char)inst;
	return ret;
}

int		board_iseq(t_board *bd1, t_board *bd2)
{
	if (bd1->na != bd2->na || bd1->nb != bd2->nb)
		return (0);
	return (ft_lstiseq(bd1->a, bd2->a) * ft_lstiseq(bd1->b, bd2->b));
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		calc_h(t_board *bd)
{
	t_list	*tmp;
	int		val;
	int		i;
	int		min;

	min = 2147483647;
	i = 0;
	while (i < bd->na + bd->nb)
	{
		val = 0;
		if (bd->b)
		{
			tmp = bd->b->bef;
			while (1)
			{
				val += dist(i++, tmp->n);
				if (i == bd->na + bd->nb)
					i = 0;
				if (tmp == bd->b)
					break ;
				tmp = tmp->bef;
			}
		}
		if (bd->a)
		{
			tmp = bd->a;
			while (1)
			{
				val += dist(i++, tmp->n);
				if (i == bd->na + bd->nb)
					i = 0;
				tmp = tmp->next;
				if (tmp == bd->a)
					break ;
			}
		}
		val += ft_min(i, bd->na + bd->nb - i) + (bd->nb);
		min = ft_min(min, val);
		i++;
	}
	return (min);
}

void	astar(t_board *bd, int direct, t_dp *dp, t_inst *inst)
{
	t_priq	*root;
	t_dp	*cur;

	if (dp)
	{
		cur = dp_pick(dp, bd, bd->na, bd->nb);
		if (cur->hist)
		{
			write_inst(inst, cur->hist, cur->g);
			return ;
		}
	}
	root = priq_init(bd);
	while (root->count)
	{
		t_node now = priq_pop(root);
		if (calc_h(now.bd) == 0)
		{
			write_inst(inst, now.hist, now.g);
			if (dp)
			{
				cur->hist = (char*)malloc(sizeof(char) * now.g);
				memcpy(cur->hist, now.hist, now.g);
				cur->bd = board_cp(now.bd);
				cur->g = now.g;
			}
			free(now.hist);
			board_clear(now.bd);
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
	priq_free(root);
}