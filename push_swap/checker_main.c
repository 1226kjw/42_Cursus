#include "checker.h"
#include <stdio.h>
#include <stdlib.h>

void	pre_pro(t_board *bd, int *ans)
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
	i = -1;
	while (++i < bd->na + bd->nb)
		ans[i] = i;
}

int		comp(const void *a, const void *b)
{
	int		*na;
	int		*nb;

	na = (int*)a;
	nb = (int*)b;
	if (*na == *nb)
		err_msg("Error\n");
	return (*na - *nb);
}

int		main(int argc, char **argv)
{
	t_board	*bd;
	char	*line;
	int		i;
	int		*ans;

	setbuf(stdout, 0);
	bd = board_init(argc, argv);
	if (argc == 1 || !bd)
		err_msg("Error\n");
	i = 0;
	ans = (int*)malloc(sizeof(int) * bd->na);
	while (i < bd->na)
	{
		ans[i] = bd->a->n;
		bd->a = bd->a->next;
		i++;
	}
	qsort(ans, bd->na, sizeof(int), comp);
	pre_pro(bd, ans);
	while (get_next_line(0, &line) == 1)
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
		else
			continue;//err_msg("Error\n");
		free(line);
	}
	if (bd->b == 0 && ft_lstsorted(bd->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
