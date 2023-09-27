#include "philo.h"

static bool is_dead(t_philo *philo)
{
	philo = (void *)philo;
	if(false)
		return(true);
	return(false);
}

static bool death_game(t_philo *philo)
{
	put_log(philo,THINK);
	if(philo->id % 2 == 0)
		usleep(200);
	if(pthread_mutex_lock(&philo->left_fork->fork) != 0)
		ft_put_error(PTHREAD_ERROR);
	put_log(philo,BEFORE_EAT);
	if(pthread_mutex_lock(&philo->right_fork->fork) != 0)
		ft_put_error(PTHREAD_ERROR);
	put_log(philo,BEFORE_EAT);
	put_log(philo,EAT);
	if (is_dead(philo))
	{
		put_log(philo, DIED);
		return(false);
	}
	gettimeofday(&philo->last_time, NULL);
	usleep(philo->info->time_eat * 1000);
	if(pthread_mutex_unlock(&philo->left_fork->fork) != 0)
		ft_put_error(PTHREAD_ERROR);
	if(pthread_mutex_unlock(&philo->right_fork->fork) != 0)
		ft_put_error(PTHREAD_ERROR);
	put_log(philo,SLEEP);
	usleep(philo->info->time_sleep * 1000);
	put_log(philo,THINK);
	return(true);
}

void *dead_or_alive(void *arg)
{
	t_philo *philo;
	int cnt;

	philo = (t_philo *)arg;
	cnt = 0;
	while(true)
	{
		if(cnt == philo->info->must_eat)
			break ;
		if (death_game(philo))
			break ;
		cnt++;
	}
	return (NULL);
}
