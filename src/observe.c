#include "philo.h"

static bool happy_end(t_philo *philo)
{
	bool flag;

	flag = false;
	if (is_stuffed(philo))
	{
		pthread_mutex_lock(&philo->share->mutex_finish); 
		philo->share->finish = true;
		flag = true;
		pthread_mutex_unlock(&philo->share->mutex_finish);
	}
	return(flag);
}

static bool bad_end(t_philo *philo)
{
	bool flag;

	flag = false;
	if(is_dead(philo))
	{
		pthread_mutex_lock(&philo->share->mutex_finish); 
		philo->share->finish = true;
		flag = true;
		pthread_mutex_unlock(&philo->share->mutex_finish);
	}
	return(flag);
}

void *observe(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(true)
	{
		if(happy_end(philo))
			break;
		else if(bad_end(philo))
			break;
	}
	return(NULL);
}
