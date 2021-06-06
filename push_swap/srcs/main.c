#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	t_board	*bd;
	void	(*inst[11])(t_board *bd) = {board_sa, board_sb, board_ss, board_pa,
		board_pb, board_ra, board_rb, board_rr, board_rra, board_rrb, board_rrr};

	bd = board_init(argc, argv);
	if (!bd)
		err_msg("Error\n");
}
