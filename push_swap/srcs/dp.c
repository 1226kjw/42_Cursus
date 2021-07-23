#include "push_swap.h"

t_dp	*dp_init(void)
{
	t_dp	*dp;
	int		i;

	dp = (t_dp*)malloc(sizeof(t_dp));
	i = -1;
	while (++i < ASTAR_MAX)
		dp->next[i] = 0;
	dp->hist = 0;
	dp->g = 0;
	dp->bd = 0;
	return (dp);
}

t_dp	*dp_pick(t_dp *dp, t_board *bd, int a, int b)
{
	t_list	*tmp;
	t_dp	*cur;
	int		i;

	i = -1;
	cur = dp;
	if (a)
	{
		tmp = bd->a;
		while (++i < ASTAR_MAX)
		{
			if (!cur->next[tmp->n])
				cur->next[tmp->n] = dp_init();
			cur = cur->next[tmp->n];
			tmp = tmp->next;
		}
	}
	else if (b)
	{
		tmp = bd->b;
		while (++i < ASTAR_MAX)
		{
			if (!cur->next[tmp->n])
				cur->next[tmp->n] = dp_init();
			cur = cur->next[tmp->n];
			tmp = tmp->next;
		}
	}
	else
		err_msg("dp error\n");
	return (cur);
}

void	dp_print(t_dp *dp, int depth)
{
	int		i;

	i = -1;
	while (++i < ASTAR_MAX)
	{
		if (dp->next[i])
			dp_print(dp->next[i], depth+1);
	}
	if (dp->hist)
		for(int j=0;j<dp->g;j++)
			printf("%d ", dp->hist[j]);
	if (dp->hist)
		printf("\n");
}

void	dp_free(t_dp *dp)
{
	int		i;

	i = -1;
	while (++i < ASTAR_MAX)
		if (dp->next[i])
			dp_free(dp->next[i]);
	if (dp->hist)
		free(dp->hist);
	free(dp);
}
