#include "astar.h"
#include "priqueue.h"

int	calc_b(t_board *bd, int *i)
{
	t_list	*tmp;
	int		val;

	val = 0;
	if (bd->b)
	{
		tmp = bd->b->bef;
		while (1)
		{
			val += dist((*i)++, tmp->n);
			if (*i == bd->na + bd->nb)
				*i = 0;
			if (tmp == bd->b)
				break ;
			tmp = tmp->bef;
		}
	}
	return (val);
}

int	calc_a(t_board *bd, int *i)
{
	t_list	*tmp;
	int		val;

	val = 0;
	if (bd->a)
	{
		tmp = bd->a;
		while (1)
		{
			val += dist((*i)++, tmp->n);
			if (*i == bd->na + bd->nb)
				*i = 0;
			tmp = tmp->next;
			if (tmp == bd->a)
				break ;
		}
	}	
	return (val);
}

int	calc_h(t_board *bd)
{
	int		val;
	int		i;
	int		min;

	min = 2147483647;
	i = 0;
	while (i < bd->na + bd->nb)
	{
		val = calc_b(bd, &i);
		val += calc_a(bd, &i);
		val += ft_min(i, bd->na + bd->nb - i) + bd->nb;
		min = ft_min(min, val);
		i++;
	}
	return (min);
}

void	astar(t_board *bd, int direct, t_inst *inst)
{
	t_priq	*root;
	t_node	now;
	int		i;

	root = priq_init(bd);
	while (root->count)
	{
		now = priq_pop(root);
		if (calc_h(now.bd) == 0)
		{
			write_inst(inst, now.hist, now.g);
			break ;
		}
		i = -1;
		while (++i <= 4 + direct * 6)
			priq_push(root, node_init(now, i));
		priq_free(0, &now);
	}
	if (!direct)
		board_clear(bd);
	priq_free(root, &now);
}
