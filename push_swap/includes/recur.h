#ifndef RECUR_H
# define RECUR_H

# include "astar.h"
# include "board.h"
# include "dp.h"
# include "inst.h"

void	atob(t_board *bd, int count, int min, int max, t_dp **dp, t_inst *inst);
void	btoa(t_board *bd, int count, int min, int max, t_dp **dp, t_inst *inst);

#endif