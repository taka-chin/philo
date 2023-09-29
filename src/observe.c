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
	if(philo != NULL)
		return (true);
	else
		return(false);
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
