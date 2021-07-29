#include "checker.h"
#include <stdio.h>
#include <stdlib.h>

void	bubblesort(int *ans, int c)
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
				err_msg("Error\n");
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
	bubblesort(ans, bd->na);
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

int	valid_inst(t_board *bd, char *line, int *flag)
{
	if (!ft_strcmp(line, "sa"))
		board_sa(bd);
	else if (!ft_strcmp(line, "sb"))
		board_sb(bd);
	else if (!ft_strcmp(line, "ss"))
		board_ss(bd);
	else if (!ft_strcmp(line, "pa"))
		board_pa(bd);
	else if (!ft_strcmp(line, "pb"))
		board_pb(bd);
	else if (!ft_strcmp(line, "ra"))
		board_ra(bd);
	else if (!ft_strcmp(line, "rb"))
		board_rb(bd);
	else if (!ft_strcmp(line, "rr"))
		board_rr(bd);
	else if (!ft_strcmp(line, "rra"))
		board_rra(bd);
	else if (!ft_strcmp(line, "rrb"))
		board_rrb(bd);
	else if (!ft_strcmp(line, "rrr"))
		board_rrr(bd);
	else if (++*flag)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_board	*bd;
	char	*line;
	int		*ans;
	int		flag;

	flag = 0;
	bd = board_init(argc, argv);
	if (argc == 1 || !bd)
		err_msg("Error\n");
	ans = (int *)malloc(sizeof(int) * bd->na);
	pre_pro(bd, ans, -1);
	while (get_next_line(0, &line) == 1)
	{
		if (valid_inst(bd, line, &flag))
			break ;
		free(line);
	}
	free(line);
	if (flag)
		write(2, "Error\n", 6);
	else if (bd->b == 0 && ft_lstsorted(bd->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	board_clear(bd);
}
