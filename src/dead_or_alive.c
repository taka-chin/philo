#include "philo.h"

bool is_dead(t_philo *philo)
{
	struct timeval tp;
	long int judge_time;
	long int log_time;
	bool	tmp;

	tmp = false;
	pthread_mutex_lock(&philo->mutex_philo);
	judge_time = philo->active_time.tv_sec *1000;
	judge_time += philo->active_time.tv_usec /1000;
	if(judge_time >= philo->share->info->time_die *1000)
	{
		log_time = (tp.tv_sec - philo->share->start_time.tv_sec) * 1000000;
		log_time += tp.tv_usec - philo->share->start_time.tv_usec;
		log_time /= 1000;
		printf("%ld %d died\n",log_time,philo->id);
		philo->share->finish = true;
		tmp = true;
	}
	pthread_mutex_unlock(&philo->mutex_philo);
	return(tmp);
}

bool check_finish(t_philo *philo)
{
	bool tmp;
	pthread_mutex_lock(&philo->share->mutex_finish);
	tmp = philo->share->finish;
	pthread_mutex_unlock(&philo->share->mutex_finish);
	return (tmp);
}

static void	mutex_gettimeofday(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_philo);
	gettimeofday(&philo->active_time, NULL);
	pthread_mutex_unlock(&philo->mutex_philo);
}

static bool death_game(t_philo *philo)
{
	if(check_finish(philo))
		return(true);
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
	mutex_gettimeofday(philo);
	usleep(philo->share->info->time_eat *1000);
	if(pthread_mutex_unlock(&philo->left_fork->fork) != 0)
		ft_put_error(PTHREAD_ERROR);
	if(pthread_mutex_unlock(&philo->right_fork->fork) != 0)
		ft_put_error(PTHREAD_ERROR);
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
		if(cnt == philo->share->info->must_eat)
			break ;
		/* if (check_finish(philo)) */
		/* 	break ; */
		if (death_game(philo))
			break ;
		cnt++;
	}
	return (NULL);
}
