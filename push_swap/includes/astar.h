#ifndef ASTAR_H
# define ASTAR_H

# include "board.h"
# include "list.h"

# include <stdlib.h>

typedef struct	s_node
{
	int			g;
	int			f;
	char		*hist;
	t_board		*bd;
}				t_node;

t_node		node_init(t_node now, int inst);
int			board_iseq(t_board *bd1, t_board *bd2);
int			calc_h(t_board *bd);

#endif
