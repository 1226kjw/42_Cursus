#ifndef DP_H
# define DP_H

# ifndef ASTAR_MAX
#  define ASTAR_MAX 5
# endif

# include <stdio.h>

typedef struct	s_dp
{
	struct s_dp	*next[ASTAR_MAX];
	char			*hist;
	int				g;
	t_board			*bd;
}				t_dp;

t_dp	*dp_init(void);
t_dp	*dp_pick(t_dp *dp, t_board *bd, int a, int b);
void	dp_free(t_dp *dp);
#endif
