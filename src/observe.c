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

void	*observe(t_philo *philo)
{
	while(true)
	{
		if(get_thread_num(philo->share) == -1)
			break;
		usleep(100);
	}
	while (true)
	{
		if (bad_end(philo) || happy_end(philo))
			break ;
		usleep(100);
	}
	return (NULL);
}
