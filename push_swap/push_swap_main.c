#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int	comp(const void *a, const void *b)
{
	int		*na;
	int		*nb;

	na = (int *)a;
	nb = (int *)b;
	if (*na == *nb)
		err_msg("Error\n");
	return (*na - *nb);
}

void	pre_pro(t_board *bd, int *ans, int i)
{
	t_list	*tmp;

	while (++i < bd->na)
	{
		ans[i] = bd->a->n;
		bd->a = bd->a->next;
	}
	qsort(ans, bd->na, sizeof(int), comp);
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
	i = -1;
	while (++i < bd->na + bd->nb)
		ans[i] = i;
	free(ans);
}

int	main(int argc, char **argv)
{
	t_board	*bd;
	int		*ans;
	t_inst	inst;

	inst_init(&inst);
	bd = board_init(argc, argv);
	if (!bd)
		err_msg("Error\n");
	ans = (int *)malloc(sizeof(int) * bd->na);
	pre_pro(bd, ans, -1);
	if (bd->na < 12)
		astar(bd, 1, &inst);
	else
		atob(bd, bd->na, 0, &inst);
	while (comp_inst(&inst))
		;
	print_inst(&inst, -1);
	board_clear(bd);
}
