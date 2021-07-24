#include "recur.h"

t_board	*newboard_only_b(t_board *bd, int count, int min)
{
	t_board		*nb;
	t_list		*cur;
	int			i;

	nb = (t_board *)malloc(sizeof(t_board));
	cur = bd->b;
	nb->a = 0;
	nb->b = 0;
	nb->na = 0;
	nb->nb = count;
	i = -1;
	while (++i < count)
	{
		ft_lstadd_last(&nb->b, ft_lstnew(cur->n - min));
		cur = cur->next;
	}
	return (nb);
}

void	board_merge_b(t_board *org, int count, int min)
{
	int		i;

	org->na += count;
	i = count;
	while (--i >= 0)
	{
		ft_lstadd_front(&org->a, ft_lstnew(i + min));
		free(ft_lstdel_front(&org->b));
	}
	org->nb -= count;
}

void	btoa(t_board *bd, int count, int min, t_inst *inst)
{
	t_board	*newboard;
	int		pivot[2];
	int		n_ra;
	int		n_rb;
	int		n_pa;
	int		i;
	int		max;

	if (count <= ASTAR_MAX)
	{
		newboard = newboard_only_b(bd, count, min);
		astar(newboard, 0, inst);
		board_clear(newboard);
		board_merge_b(bd, count, min);
		return ;
	}
	max = min + count - 1;
	pivot[0] = (min * 2 + max) / 3;
	pivot[1] = (min + max * 2) / 3;
	n_ra = 0;
	n_rb = 0;
	n_pa = 0;
	i = -1;
	while (++i < count)
	{
		if (bd->b->n <= pivot[0])
		{
			board_rb(bd);
			write_inst(inst, "\x6", 1);
			n_rb++;
		}
		else
		{
			board_pa(bd);
			write_inst(inst, "\x3", 1);
			n_pa++;
			if (bd->a->n <= pivot[1])
			{
				board_ra(bd);
				write_inst(inst, "\x5", 1);
				n_ra++;
			}
		}
	}
	atob(bd, n_pa - n_ra, pivot[1] + 1, inst);
	i = -1;
	while (++i < n_ra && i < n_rb)
	{
		board_rrr(bd);
		write_inst(inst, "\xa", 1);
	}
	while (i < n_ra)
	{
		board_rra(bd);
		write_inst(inst, "\x8", 1);
		i++;
	}
	while (i < n_rb)
	{
		board_rrb(bd);
		write_inst(inst, "\x9", 1);
		i++;
	}
	atob(bd, n_ra, pivot[0] + 1, inst);
	btoa(bd, n_rb, min, inst);
}
