#ifndef RECUR_H
# define RECUR_H

# ifndef ASTAR_MAX
#  define ASTAR_MAX 5
# endif

# include "astar.h"
# include "board.h"
# include "inst.h"

void	atob(t_board *bd, int count, int min, t_inst *inst);
void	btoa(t_board *bd, int count, int min, t_inst *inst);

#endif
