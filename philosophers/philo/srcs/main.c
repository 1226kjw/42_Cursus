#include "philo.h"

long	my_gettime(long bef)
{
	struct timeval	t;
	long			now;

	t.tv_sec = 0;
	t.tv_usec = 0;
	gettimeofday(&t, 0);
	now = t.tv_sec * 1000L + t.tv_usec / 1000L;
	return (now - bef);
}

t_env	init_param(int argc, char **argv)
{
	t_env	ret;
	int		i;

	if (argc < 5 || argc > 6)
		err_msg("invalid num of args.\n");
	memset(&ret, 0, sizeof(t_env));
	i = 0;
	while (++i < argc)
		if (!ft_isdigit(argv[i]))
			err_msg("Non numeric character exists on arg\n");
	ret.n = ft_atoi(argv[1]);
	ret.die = ft_atoi(argv[2]);
	ret.eat = ft_atoi(argv[3]);
	ret.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ret.end = ft_atoi(argv[5]);
	else
		ret.end = -1;
	if (ret.end == 0)
		err_msg("number of meals to eat cannot 0\n");
	return (ret);
}

pthread_mutex_t	*init_mutex(t_env p)
{
	int				i;
	pthread_mutex_t	*m;

	m = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p.n);
	if (!m)
		err_msg("malloc error!\n");
	i = -1;
	while (++i < p.n)
		pthread_mutex_init(&m[i], 0);
	return (m);
}

t_philo	*init_philo(t_env p, pthread_mutex_t *m)
{
	t_philo			*philo;
	int				i;
	struct timeval	t;

	philo = (t_philo *)malloc(sizeof(t_philo) * p.n);
	memset(philo, 0, sizeof(t_philo) * p.n);
	if (!philo)
		err_msg("malloc error!\n");
	philo[0].prog = (int *)malloc(sizeof(int));
	*(philo[0].prog) = P_ALIVE;
	philo[0].fullcount = (int *)malloc(sizeof(int));
	*(philo[0].fullcount) = 0;
	philo[0].status_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[0].status_mutex, 0);
	i = -1;
	gettimeofday(&t, 0);
	while (++i < p.n)
	{
		philo[i].prog = philo[0].prog;
		philo[i].fullcount = philo[0].fullcount;
		philo[i].start = my_gettime(0L);
		philo[i].id = i + 1;
		philo[i].left_fork = &m[i];
		philo[i].right_fork = &m[(i + 1) % p.n];
		philo[i].status_mutex = philo[0].status_mutex;
		philo[i].env = p;
	}
	return (philo);
}

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
			pthread_mutex_unlock(p->right_fork);
			pthread_mutex_unlock(p->left_fork);
			*p->prog = P_DIE;
		}
		if (p->env.end != -1 && p->count >= p->env.end)
		{
			++*p->fullcount;
			if (*p->fullcount == p->env.n)
			{
				printf("%6ldms: All philosophers are full\n",
						my_gettime(p->start));
				*p->prog = P_FULL;
			}
		}
	}
	return (0);
}

void	eating(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	pthread_mutex_lock(p->right_fork);
	print_msg("has take a fork\n", p);
	print_msg("is eating\n", p);
	p->last = my_gettime(0L);
	usleep(p->env.eat * 1000);
	p->count++;
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

void	*thread_func(void *arg)
{
	t_philo		*p;
	pthread_t	monit;

	p = (t_philo *)arg;
	p->last = my_gettime(0L);
	pthread_create(&monit, 0, monit_func, arg);
	if (p->id % 2 == 0)
		usleep(p->env.eat * 500);
	while (*p->prog == P_ALIVE)
	{
		eating(p);
		if (p->env.end == -1 || p->count < p->env.end)
			print_msg("is sleeping\n", p);
		usleep(p->env.sleep * 1000);
		print_msg("is thinking\n", p);
	}
	pthread_join(monit, 0);
	return ((void *)&p->status);
}

void	make_thread(t_philo *philo, t_env p)
{
	int		i;

	i = -1;
	while (++i < p.n)
		if (pthread_create(&philo[i].thread, 0, thread_func, &philo[i]) < 0)
			err_msg("pthread create error\n");
}

void	end_thread(t_philo *philo, t_env p, pthread_mutex_t *m)
{
	int		i;

	i = -1;
	while (++i < p.n)
		pthread_join(philo[i].thread, 0);
	while (--i >= 0)
		pthread_mutex_destroy(&m[i]);
	pthread_mutex_destroy(philo->status_mutex);
	free(philo->status_mutex);
	free(philo->prog);
	free(philo->fullcount);
	free(m);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_env			p;
	pthread_mutex_t	*m_fork;
	t_philo			*philo;

	p = init_param(argc, argv);
	m_fork = init_mutex(p);
	philo = init_philo(p, m_fork);
	make_thread(philo, p);
	end_thread(philo, p, m_fork);
}
