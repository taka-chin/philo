#include "philo.h"

// static void	mutex_gettimeofday(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->mutex_philo);
// 	philo->active_time = create_time(philo) ;
// 	pthread_mutex_unlock(&philo->mutex_philo);
// }

static void	death_game(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&philo->left_fork->fork);
	put_log(philo, BEFORE_EAT);
	pthread_mutex_lock(&philo->right_fork->fork);
	put_log(philo, BEFORE_EAT);
	put_log(philo, EAT);
	// mutex_gettimeofday(philo);
	pthread_mutex_lock(&philo->mutex_philo);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex_philo);
	usleep(philo->share->info->time_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
	put_log(philo, SLEEP);
	usleep(philo->share->info->time_sleep * 1000);
	put_log(philo, THINK);
}

void	*dead_or_alive(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	put_log(philo, THINK);
	while (true)
	{
		if (check_finish(philo))
			break ;
		death_game(philo);
	}
	return (NULL);
}
