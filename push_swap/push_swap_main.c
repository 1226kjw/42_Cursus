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

void	pre_pro(t_board *bd, int *ans, t_dp *dp[2])
{
	int		i;
	t_list	*tmp;

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
	free(ans);
	dp[0] = dp_init();
	dp[1] = dp_init();
}

int	main(int argc, char **argv)
{
	t_board	*bd;
	int		*ans;
	int		i;
	t_dp	*dp[2];
	t_inst	inst;

	i = -1;
	while (++i < 65536)
		inst.inst[i] = -1;
	inst.c = 0;
	inst.better = 0;
	bd = board_init(argc, argv);
	if (!bd)
		err_msg("Error\n");
	ans = (int *)malloc(sizeof(int) * bd->na);
	i = 0;
	while (i < bd->na)
	{
		ans[i] = bd->a->n;
		bd->a = bd->a->next;
		i++;
	}
	qsort(ans, bd->na, sizeof(int), comp);
	pre_pro(bd, ans, dp);
	if (bd->na < 12)
		astar(bd, 1, 0, &inst);
	else
		atob(bd, bd->na, 0, bd->na - 1, dp, &inst);
	while (comp_inst(&inst))
		;
	print_inst(&inst, -1);
	board_clear(bd);
	dp_free(dp[0]);
	dp_free(dp[1]);
}
