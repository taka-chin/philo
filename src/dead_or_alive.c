#include "philo.h"

static void	mutex_gettimeofday(t_philo *philo)
{
	long int time;
	pthread_mutex_lock(&philo->mutex_philo);
	time = create_time(philo);
	philo->active_time = time;
	pthread_mutex_unlock(&philo->mutex_philo);
}

static bool death_game(t_philo *philo)
{
	put_log(philo,THINK);
	if(philo->id % 2 == 0)
		usleep(200);
	pthread_mutex_lock(&philo->left_fork->fork);
	put_log(philo,BEFORE_EAT);
	pthread_mutex_lock(&philo->right_fork->fork);
	put_log(philo,BEFORE_EAT);
	put_log(philo,EAT);
	philo->eat_count++;
	mutex_gettimeofday(philo);
	usleep(philo->share->info->time_eat *1000);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
	put_log(philo,SLEEP);
	usleep(philo->share->info->time_sleep *1000);
	put_log(philo,THINK);
	return(false);
}

void *dead_or_alive(void *arg)
{
	t_philo *philo;
	int cnt;

	philo = (t_philo *)arg;
	cnt = 0;
	while(true)
	{
		if(check_finish(philo))
			break;
		if (death_game(philo))
			break ;
		cnt++;
	}
	return (NULL);
}
