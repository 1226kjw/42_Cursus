#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	t_board	*bd;

	bd = board_init(argc, argv);
	if (!bd)
		err_msg("Error\n");
}
