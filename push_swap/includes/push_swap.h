#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ASTAR_MAX 5

# include "list.h"
# include "utils.h"
# include "board.h"
# include "priqueue.h"
# include "astar.h"
# include "dp.h"

void	atob(t_board *bd, int count, int min, int max, t_dp **dp);
void	btoa(t_board *bd, int count, int min, int max, t_dp **dp);

#endif
