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

void	split_b(t_board *bd, t_inst *inst, int pivot[2], int n[3])
{
	if (bd->b->n <= pivot[0])
	{
		board_rb(bd);
		write_inst(inst, "\x6", 1);
		n[1]++;
	}
	else
	{
		board_pa(bd);
		write_inst(inst, "\x3", 1);
		n[2]++;
		if (bd->a->n <= pivot[1])
		{
			board_ra(bd);
			write_inst(inst, "\x5", 1);
			n[0]++;
		}
	}
}

void	rewind_b(t_board *bd, t_inst *inst, int n_ra, int n_rb)
{
	int		i;

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
}

void	btoa(t_board *bd, int count, int min, t_inst *inst)
{
	int		pivot[2];
	int		n[3];
	int		i;

	if (count <= ASTAR_MAX)
	{
		astar(newboard_only_b(bd, count, min), 0, inst);
		board_merge_b(bd, count, min);
		return ;
	}
	pivot[0] = (min * 2 + min + count - 1) / 3;
	pivot[1] = (min + (min + count - 1) * 2) / 3;
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	i = -1;
	while (++i < count)
		split_b(bd, inst, pivot, n);
	atob(bd, n[2] - n[0], pivot[1] + 1, inst);
	rewind_b(bd, inst, n[0], n[1]);
	if (!ft_lstsorted(bd->a))
		atob(bd, n[0], pivot[0] + 1, inst);
	btoa(bd, n[1], min, inst);
}
