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
	t_philo	*philo_p;
	int		i;

	i = 0;
	while (i < philo->share->info->number)
	{
		philo_p = &philo[i++];
		pthread_create(&philo_p->thread, NULL, dead_or_alive, philo_p);
	}
	pthread_mutex_lock(&philo->share->mutex_finish);
	philo->share->thread_num = -1;
	gettimeofday(&philo->share->start_time, NULL);
	pthread_mutex_unlock(&philo->share->mutex_finish);
	observe(philo);
}

void	pthreads_destory(t_fork *fork, t_share *share, t_philo *philo,int number)
{
	t_fork	*fork_p;
	t_share	*share;
	t_philo	*philo_p;
	int		i;

	i = 0;
	pthread_mutex_destroy(&share->mutex_finish);
	while (i < number)
	{
		fork_p = &fork[i];
		philo_p = &philo[i];
		pthread_mutex_destroy(&fork_p->fork);
		pthread_mutex_destroy(&filo_p->fork);
		i++;
	}
}
