#include "philo.h"

void	print_msg(char *str, t_philo *p)
{
	pthread_mutex_lock(p->status_mutex);
	if (*p->prog == P_ALIVE && p->status != P_FULL)
		printf("%6ldms: %3d %s", my_gettime(p->start), p->id, str);
	pthread_mutex_unlock(p->status_mutex);
}

void	*monit_func(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	while (*p->prog == P_ALIVE)
	{
		if (my_gettime(p->last) >= p->env.die)
		{
			print_msg("is died\n", p);
			*p->prog = P_DIE;
		}
		if (p->env.end != -1 && p->count == p->env.end)
		{
			p->count++;
			++*p->fullcount;
			if (*p->fullcount == p->env.n)
			{
				pthread_mutex_lock(p->status_mutex);
				printf("%6ldms: All philosophers are full\n",
					my_gettime(p->start));
				*p->prog = P_FULL;
				pthread_mutex_unlock(p->status_mutex);
			}
		}
	}
	return (0);
}
