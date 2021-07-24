#include "recur.h"

t_board	*newboard_only_a(t_board *bd, int count, int min)
{
	t_board		*nb;
	t_list		*cur;
	int			i;

	nb = (t_board *)malloc(sizeof(t_board));
	cur = bd->a;
	nb->a = 0;
	nb->b = 0;
	nb->na = count;
	nb->nb = 0;
	i = -1;
	while (++i < count)
	{
		ft_lstadd_last(&nb->a, ft_lstnew(cur->n - min));
		cur = cur->next;
	}
	return (nb);
}

void	board_merge_a(t_board *org, int count, int min)
{
	t_list	*cur_org;
	int		i;

	cur_org = org->a;
	i = -1;
	while (++i < count)
	{
		cur_org->n = i + min;
		cur_org = cur_org->next;
	}
}

void	split_a(t_board *bd, t_inst *inst, int pivot[2], int n[3])
{
	if (bd->a->n > pivot[1])
	{
		board_ra(bd);
		write_inst(inst, "\x5", 1);
		n[0]++;
	}
	else
	{
		board_pb(bd);
		write_inst(inst, "\x4", 1);
		n[2]++;
		if (bd->b->n > pivot[0])
		{
			board_rb(bd);
			write_inst(inst, "\x6", 1);
			n[1]++;
		}
	}
}

void	rewind_a(t_board *bd, t_inst *inst, int n_ra, int n_rb)
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

void	atob(t_board *bd, int count, int min, t_inst *inst)
{
	int		pivot[2];
	int		n[3];
	int		i;

	if (count <= ASTAR_MAX)
	{
		astar(newboard_only_a(bd, count, min), 0, inst);
		board_merge_a(bd, count, min);
		return ;
	}
	pivot[0] = (min * 2 + min + count - 1) / 3;
	pivot[1] = (min + (min + count - 1) * 2) / 3;
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	i = -1;
	while (++i < count)
		split_a(bd, inst, pivot, n);
	rewind_a(bd, inst, n[0], n[1]);
	atob(bd, n[0], pivot[1] + 1, inst);
	btoa(bd, n[1], pivot[0] + 1, inst);
	btoa(bd, n[2] - n[1], min, inst);
}
