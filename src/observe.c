#include "philo.h"

static bool	happy_end(t_philo *philo)
{
	bool	flag;

	flag = false;
	if (is_stuffed(philo))
	{
		pthread_mutex_lock(&philo->share->mutex_finish);
		philo->share->finish = true;
		pthread_mutex_unlock(&philo->share->mutex_finish);
		flag = true;
	}
	return (flag);
}

static bool	bad_end(t_philo *philo)
{
	bool	flag;

	flag = false;
	if (is_dead(philo))
	{
		pthread_mutex_lock(&philo->share->mutex_finish);
		philo->share->finish = true;
		pthread_mutex_unlock(&philo->share->mutex_finish);
		flag = true;
	}
	return (flag);
}

/* void	*observe(void *arg) */
void	*observe(t_philo *philo)
{
	while(true)
	{
		pthread_mutex_lock(philo->mutex_philo);
		if(philo->share->thread_num == philo->share->info->number)
			break;
		pthread_mutex_unlock(philo->mutex_philo);
	}
	pthread_mutex_unlock(philo->mutex_philo);
	while (true)
	{
		if (happy_end(philo) || bad_end(philo))
			break ;
		usleep(100);
	}
	return (NULL);
}
