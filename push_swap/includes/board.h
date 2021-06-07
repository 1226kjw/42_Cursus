#ifndef BOARD_H
# define BOARD_H

# include "list.h"

typedef struct	s_board
{
	t_list		*a;
	t_list		*b;
	int			na;
	int			nb;
}				t_board;

t_board			*board_new(t_list *a, t_list *b, int na, int nb);
t_board			*board_init(int argc, char **argv);
t_board			*board_cp(t_board *bd);
void			board_print(t_board *bd, int *ans);
void			board_clear(t_board *bd);
void			board_sa(t_board *bd);
void			board_sb(t_board *bd);
void			board_ss(t_board *bd);
void			board_pa(t_board *bd);
void			board_pb(t_board *bd);
void			board_ra(t_board *bd);
void			board_rb(t_board *bd);
void			board_rr(t_board *bd);
void			board_rra(t_board *bd);
void			board_rrb(t_board *bd);
void			board_rrr(t_board *bd);

#endif
