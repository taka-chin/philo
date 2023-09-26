#include "philo.h"

static bool is_dead()
{
	if(false)
		return(true);
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
		if(cnt == philo->info->must_eat)
			break ;
		if(philo->id % 2 == 0)
			usleep(200);
		if(pthread_mutex_lock(&philo->left_fork->fork) != 0)
		{
			all_free();
			ft_put_error(PTHREAD_ERROR);
		}
		put_log(philo->id,BEFORE_EAT);
		if(pthread_mutex_lock(&philo->right_fork->fork) != 0)
		{
			all_free();
			ft_put_error(PTHREAD_ERROR);
		}
		put_log(philo->id,BEFORE_EAT);
		put_log(philo->id,EAT);
		if(pthread_mutex_unlock(&philo->left_fork->fork) != 0)
		{
			all_free();
			ft_put_error(PTHREAD_ERROR);
		}
		if(pthread_mutex_unlock(&philo->right_fork->fork) != 0)
		{
			all_free();
			ft_put_error(PTHREAD_ERROR);
		}
		usleep(philo->info->time_eat);
		put_log(philo->id,SLEEP);
		usleep(philo->info->time_sleep);
		put_log(philo->id,THINK);
		if(is_dead())
			put_log(philo->id,DIED);
		cnt++;
	}
	return (NULL);
}
