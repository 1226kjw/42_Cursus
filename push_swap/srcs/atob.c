#include "recur.h"

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

void	board_merge_a(t_board *org, int count, int min)
{
	t_list	*cur_org;

	cur_org = org->a;
	for(int i=0;i<count;i++)
	{
		cur_org->n = i + min;
		cur_org = cur_org->next;
	}
}

void	atob(t_board *bd, int count, int min, int max, t_dp **dp, t_inst *inst)
{
	int		pivot[2];
	int		n_ra;
	int		n_rb;
	int		n_pb;
	int		i;

	if (count <= ASTAR_MAX)
	{
		t_board *newboard = newboard_only_a(bd, count, min);
		astar(newboard, 0, dp[0], inst);
		board_clear(newboard);
		board_merge_a(bd, count, min);
		return ;
	}
	pivot[0] = (min * 2 + max) / 3;
	pivot[1] = (min + max * 2) / 3;
	n_ra = 0;
	n_rb = 0;
	n_pb = 0;
	for(int i=0;i<count;i++)
	{
		if (bd->a->n > pivot[1])
		{
			board_ra(bd);
			write_inst(inst, "\x5", 1);
			n_ra++;
		}
		else
		{
			board_pb(bd);
			write_inst(inst, "\x4", 1);
			n_pb++;
			if (bd->b->n > pivot[0])
			{
				board_rb(bd);
				write_inst(inst, "\x6", 1);
				n_rb++;
			}
		}
	}
	for(i=0;i<n_ra && i<n_rb;i++)
	{
		board_rrr(bd);
		write_inst(inst, "\xa",1);
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
	atob(bd, n_ra, pivot[1] + 1, max, dp, inst);
	btoa(bd, n_rb, pivot[0] + 1, pivot[1], dp, inst);
	btoa(bd, n_pb - n_rb, min, pivot[0], dp, inst);
}