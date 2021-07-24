#include "board.h"

void			board_sb(t_board *bd)
{
	int			tmp;

	if (bd->nb < 2)
		return ;
	tmp = bd->b->n;
	bd->b->n = bd->b->next->n;
	bd->b->next->n = tmp;
}

void			board_ss(t_board *bd)
{
	board_sa(bd);
	board_sb(bd);
}

void			board_pa(t_board *bd)
{
	if (bd->nb < 1)
		return ;
	ft_lstadd_front(&bd->a, ft_lstdel_front(&bd->b));
	bd->na++;
	bd->nb--;
}

void			board_pb(t_board *bd)
{
	if (bd->na < 1)
		return ;
	ft_lstadd_front(&bd->b, ft_lstdel_front(&bd->a));
	bd->na--;
	bd->nb++;
}

void			board_ra(t_board *bd)
{
	if (bd->na < 2)
		return ;
	bd->a = bd->a->next;
}
