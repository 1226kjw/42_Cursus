#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int		comp(const void *a, const void *b)
{
	int		*na;
	int		*nb;

	na = (int*)a;
	nb = (int*)b;
	return (*na - *nb);
}

int		main(int argc, char **argv)
{
	t_board	*bd;
	int		*ans;
	int		i;
	void	(*inst[11])(t_board *bd) = {board_sa, board_sb, board_ss, board_pa,
		board_pb, board_ra, board_rb, board_rr, board_rra, board_rrb, board_rrr};

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
}
