#include "board.h"
#include "list.h"
#include "utils.h"
#include "astar.h"

t_board			*board_new(t_list *a, t_list *b, int na, int nb)
{
	t_board		*newbd;

	if (!(newbd = (t_board*)malloc(sizeof(t_board))))
		exit(0);
	newbd->a = a;
	newbd->b = b;
	newbd->na = na;
	newbd->nb = nb;
	return (newbd);
}

t_board			*board_init(int argc, char **argv)
{
	t_board		*bd;
	t_list		*parsed;
	int			i;
	int			j;

	parsed = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		j = 0;
		if (!ft_isspdigit(argv[1]))
			return (0);
		while (argv[1][j])
			ft_lstadd_last(&parsed, ft_lstnew(ft_atoi(argv[1], &j)));
	}
	else if (argc > 2)
	{
		i = 1;
		j = 1;
		while (i < argc)
			j *= ft_isspdigit(argv[i++]);
		if (!j)
			return (0);
		i = 1;
		while (i < argc)
		{
			j = 0;
			ft_lstadd_last(&parsed, ft_lstnew(ft_atoi(argv[i], &j)));
			i++;
		}
	}
	bd = board_new(parsed, 0, ft_lstsize(parsed), 0);
	return (bd);
}

t_board			*board_cp(t_board *bd)
{
	t_list		*newa;
	t_list		*newb;
	t_list		*tmp;

	newa = 0;
	newb = 0;
	if (bd->a)
	{
		tmp = bd->a;
		while (tmp->next != bd->a)
		{
			ft_lstadd_last(&newa, ft_lstnew(tmp->n));
			tmp = tmp->next;
		}
		ft_lstadd_last(&newa, ft_lstnew(tmp->n));
	}
	if (bd->b)
	{
		tmp = bd->b;
		while (tmp->next != bd->b)
		{
			ft_lstadd_last(&newb, ft_lstnew(tmp->n));
			tmp = tmp->next;
		}
		ft_lstadd_last(&newb, ft_lstnew(tmp->n));
	}
	return (board_new(newa, newb, bd->na, bd->nb));
}

/*void			board_print(t_board *bd)
{
	t_list		*tmp;

	tmp = bd->a;
	printf("A | ");
	if (tmp)
	{
		while (tmp->next != bd->a)
		{
			printf("%3d ", tmp->n);
			tmp = tmp->next;
		}
		printf("%3d", tmp->n);
	}
	printf("\n");
	tmp = bd->b;
	printf("B | ");
	if (tmp)
	{
		while (tmp->next != bd->b)
		{
			printf("%3d ", tmp->n);
			tmp = tmp->next;
		}
		printf("%3d", tmp->n);
	}
	printf("\n%d\n\n", calc_h(bd));
}*/

void			board_clear(t_board *bd)
{
	ft_lstclear(&bd->a);
	ft_lstclear(&bd->b);
	free(bd);
}

void			board_sa(t_board *bd)
{
	int			tmp;

	if (bd->na < 2)
		return ;
	tmp = bd->a->n;
	bd->a->n = bd->a->next->n;
	bd->a->next->n = tmp;
}

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
