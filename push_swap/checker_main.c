#include "checker.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	t_board	*bd;
	char	*line;

	bd = board_init(argc, argv);
	if (!bd)
		err_msg("Error\n");
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
			err_msg("Error\n");
		free(line);
		board_print(bd);
	}
	if (bd->b == 0 && ft_lstsorted(bd->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
