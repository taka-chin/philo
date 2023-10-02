#include "philo.h"

bool input_check(int argc, char **input)
{
	const char	*str;

	if(argc < 5 || argc >= 7)
		return (false);
	while (*++input)
	{
		str = *input;
		if (str[0] == '+' || str[0] == '-')
			str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
			{
				ft_put_error(ARGS_ERROR);
				return(false);
			}
			str++;
		}
	}
	return(true);
}

bool is_dead(t_philo *philo)
{
	long int log_time;
	bool	flag;
	struct timeval now_time;

	gettimeofday(&now_time, NULL);	
	flag = false;
	log_time = (now_time.tv_sec - philo->share->start_time.tv_sec) * 1000000;
	log_time += now_time.tv_usec - philo->share->start_time.tv_usec;
	log_time /= 1000;
	pthread_mutex_lock(&philo->mutex_philo);
	log_time = log_time - philo->active_time;
	if(log_time > philo->share->info->time_die)
	{
		log_time = create_time(philo);
		printf("%ld %d died\n",log_time,philo->id);
		pthread_mutex_lock(&philo-> share -> mutex_finish);
		philo->share->finish = true;
		pthread_mutex_unlock(&philo->share -> mutex_finish);
		flag = true;
	}
	pthread_mutex_unlock(&philo->mutex_philo);
	return(flag);
}

bool is_stuffed(t_philo *philo)
{
	bool	flag;
	t_philo *p;
	int i;

	flag = true;
	i = 0;
	if(philo->share->info->must_eat == -1)
		return(false);
	while(i < philo->share->info->number)
	{
		p = &philo[i];
		pthread_mutex_lock(&p->mutex_philo);
		if(p->eat_count < p->share->info->must_eat)
			flag = false;
		pthread_mutex_unlock(&p->mutex_philo);
		i++;
	}
	return(flag);
}

bool check_finish(t_philo *philo)
{
	bool tmp;
	pthread_mutex_lock(&philo->share->mutex_finish);
	tmp = philo->share->finish;
	pthread_mutex_unlock(&philo->share->mutex_finish);
	return (tmp);
}
