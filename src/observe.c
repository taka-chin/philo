#include "philo.h"

static bool happy_end(t_philo *philo)
{
	if(philo != NULL)
		return (true);
	else
		return(false);
}

static bool bad_end(t_philo *philo)
{
	bool flag;

	flag = false;
	if(pthread_mutex_lock(&philo->share->mutex_finish) != 0)
		ft_put_error(PTHREAD_ERROR);
	if(is_dead(philo))
	{
		philo->share->finish = true;
		flag = true;
	}
	if(pthread_mutex_unlock(&philo->share->mutex_finish) != 0)
		ft_put_error(PTHREAD_ERROR);
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
