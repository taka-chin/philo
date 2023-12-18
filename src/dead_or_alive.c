#include "philo.h"

static void	death_game(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&philo->left_fork->mutex_fork);
	put_log(philo, BEFORE_EAT);
	pthread_mutex_lock(&philo->right_fork->mutex_fork);
	put_log(philo, BEFORE_EAT);
	put_log(philo, EAT);
	pthread_mutex_lock(philo->mutex_philo);
	philo->eat_count++;
	pthread_mutex_unlock(philo->mutex_philo);
	usleep(philo->share->info->time_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->mutex_fork);
	pthread_mutex_unlock(&philo->right_fork->mutex_fork);
	put_log(philo, SLEEP);
	usleep(philo->share->info->time_sleep * 1000);
	put_log(philo, THINK);
}

int	get_thread_num(t_share *share)
{
	int	thread_num;
	
	pthread_mutex_lock(&share->mutex_finish);
	thread_num = share->thread_num;
	pthread_mutex_unlock(&share->mutex_finish);
	return (thread_num);
}

void	*dead_or_alive(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while(true)
	{
		if(get_thread_num(philo->share) == -1)
			break;
		usleep(100);
	}
	put_log(philo, THINK);
	while (true)
	{
		if (check_finish(philo))
			break ;
		death_game(philo);
	}
	return (NULL);
}
