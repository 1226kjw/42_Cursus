# include "astar.h"
#include<stdio.h>
# include<string.h>
#include<stdlib.h>
int		dist(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}

t_node	node_init(t_node now, int inst)
{
	t_node	ret;

	ret.bd = board_cp(now.bd);
	if (inst == 0 && ret.bd->na > 1)
		board_sa(ret.bd);
	else if (inst == 1 && ret.bd->nb > 1)
		board_sb(ret.bd);
	else if (inst == 2 && ret.bd->na > 1 && ret.bd->nb > 1)
		board_ss(ret.bd);
	else if (inst == 3 && ret.bd->nb > 0)
		board_pa(ret.bd);
	else if (inst == 4 && ret.bd->na > 0)
		board_pb(ret.bd);
	else if (inst == 5 && ret.bd->na > 1)
		board_ra(ret.bd);
	else if (inst == 6 && ret.bd->nb > 1)
		board_rb(ret.bd);
	else if (inst == 7 && ret.bd->na > 1 && ret.bd->nb > 1)
		board_rr(ret.bd);
	else if (inst == 8 && ret.bd->na > 1)
		board_rra(ret.bd);
	else if (inst == 9 && ret.bd->nb > 1)
		board_rrb(ret.bd);
	else if (inst == 10 && ret.bd->na > 1 && ret.bd->nb > 1)
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
		val *= 1.5;
		val += ft_min(i, bd->na + bd->nb - i) + bd->nb;
		min = ft_min(min, val);
		i++;
	}
	return (min);
}
