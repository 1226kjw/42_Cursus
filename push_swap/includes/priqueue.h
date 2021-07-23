#ifndef PRIQUEUE_H
# define PRIQUEUE_H

# ifndef MAXQUEUE
#  define MAXQUEUE 50000000
# endif

# include <stdlib.h>
# include "utils.h"
# include "astar.h"

typedef struct	s_priq
{
	t_node	heap[MAXQUEUE+1];
	int		count;
}				t_priq;

void			node_swap(t_node *n1, t_node *n2);
void			priq_push(t_priq *root, t_node data);
t_node			priq_pop(t_priq *root);
void			priq_free(t_priq *root);

#endif
