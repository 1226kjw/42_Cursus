#include "astar.h"

int	dist(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}

int	ispossible(int inst, t_board *bd, int g, char *h)
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
	return (0);
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
		return (ret);
	}
	ret.g = now.g + 1;
	ret.f = ret.g + calc_h(ret.bd);
	ret.hist = (char *)malloc(now.g + 1);
	memcpy(ret.hist, now.hist, now.g);
	ret.hist[now.g] = (char)inst;
	return (ret);
}

int	board_iseq(t_board *bd1, t_board *bd2)
{
	if (bd1->na != bd2->na || bd1->nb != bd2->nb)
		return (0);
	return (ft_lstiseq(bd1->a, bd2->a) * ft_lstiseq(bd1->b, bd2->b));
}
