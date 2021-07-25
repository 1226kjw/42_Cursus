#ifndef PRIQUEUE_H
# define PRIQUEUE_H

# ifndef MAXQUEUE
#  define MAXQUEUE 5000000
# endif

# include "astar.h"

typedef struct s_priq
{
	t_node	heap[MAXQUEUE + 1];
	int		count;
}			t_priq;

t_priq			*priq_init(t_board *bd);
void			node_swap(t_node *n1, t_node *n2);
void			priq_push(t_priq *root, t_node data);
t_node			priq_pop(t_priq *root);
void			priq_free(t_priq *root, t_node *now);

#endif
