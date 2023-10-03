#include "philo.h"

void	pthreads_join(t_philo *philo)
{
	t_philo	*p;
	int		i;

	i = 0;
	while (i < philo->share->info->number)
	{
		p = &philo[i];
		pthread_join(p->thread, NULL);
		i++;
	}
}

void	pthreads_create(t_philo *philo)
{
	t_philo			*philo_p;
	int				i;
	struct timeval	tp;

	i = 0;
	while (i < philo->share->info->number)
	{
		philo_p = &philo[i];
		if(i == philo->share->info->number)
		{
			gettimeofday(&tp, NULL);
			philo->share->start_time.tv_sec = tp.tv_sec;
			philo->share->start_time.tv_usec = tp.tv_usec;
		}
		/* philo_p->share->start_time.tv_sec = tp.tv_sec; */
		/* philo_p->share->start_time.tv_usec = tp.tv_usec; */
		pthread_create(&philo_p->thread, NULL, dead_or_alive, (void *)philo_p);
		pthread_mutex_lock(philo->mutex_philo);
		philo->share->thread_num++;
		pthread_mutex_unlock(philo->mutex_philo);
		i++;
	}
	observe(philo);
}

void	pthreads_destory(t_fork *fork, int number)
{
	t_fork	*fork_p;
	int		i;

	i = 0;
	while (i < number)
	{
		fork_p = &fork[i];
		pthread_mutex_destroy(&fork_p->fork);
		i++;
	}
}
