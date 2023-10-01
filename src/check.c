#include "philo.h"

bool input_check(char **input)
{
	const char	*str;

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
	long int judge_time;
	long int log_time;
	bool	flag;

	flag = false;
	pthread_mutex_lock(&philo->mutex_philo);
	judge_time = philo->active_time;
	if(judge_time >= philo->share->info->time_die *1000)
	{
		log_time = create_time(philo);
		printf("%ld %d died\n",log_time,philo->id);
		philo->share->finish = true;
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
		return(flag);
	while(i < philo->share->info->number)
	{
		p = &philo[i];
		pthread_mutex_lock(&p->mutex_philo);
		if(p->eat_count < p->share->info->must_eat)
			flag = false;
		pthread_mutex_unlock(&p->mutex_philo);
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
