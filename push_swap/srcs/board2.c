#include "board.h"

void			board_rb(t_board *bd)
{
	if (bd->nb < 2)
		return ;
	bd->b = bd->b->next;
}

void			board_rr(t_board *bd)
{
	board_ra(bd);
	board_rb(bd);
}

void			board_rra(t_board *bd)
{
	if (bd->na < 2)
		return ;
	bd->a = bd->a->bef;
}

void			board_rrb(t_board *bd)
{
	if (bd->nb < 2)
		return ;
	bd->b = bd->b->bef;
}

void			board_rrr(t_board *bd)
{
	board_rra(bd);
	board_rrb(bd);
}
