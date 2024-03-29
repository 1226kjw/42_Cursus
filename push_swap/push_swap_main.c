#include "push_swap.h"

void	bubblesort(int *ans, int c, t_board *bd)
{
	int		i;
	int		j;
	int		tmp;

	i = -1;
	while (++i < c)
	{
		j = 0;
		while (++j < c - i)
		{
			if (ans[j] < ans[j - 1])
			{
				tmp = ans[j];
				ans[j] = ans[j - 1];
				ans[j - 1] = tmp;
			}
			else if (ans[j] == ans[j - 1])
			{
				board_clear(bd);
				free(ans);
				err_msg("Error\n");
			}
		}
	}
}

void	pre_pro(t_board *bd, int *ans, int i)
{
	t_list	*tmp;

	while (++i < bd->na)
	{
		ans[i] = bd->a->n;
		bd->a = bd->a->next;
	}
	bubblesort(ans, bd->na, bd);
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
	if (ft_lstsorted(bd->a))
		;
	else if (bd->na < 10)
		astar(bd, 1, &inst);
	else
		atob(bd, bd->na, 0, &inst);
	while (comp_inst(&inst))
		;
	print_inst(&inst, -1);
	board_clear(bd);
}
