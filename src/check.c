#include "philo.h"

bool	input_check(int argc, char **input)
{
	const char	*str;

	if (argc < 5 || argc >= 7)
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
				return (false);
			}
			str++;
		}
	}
	return (true);
}

bool	is_dead(t_philo *philo)
{
	long int	log_time;
	long int	jugde_time;
	bool		flag;
	t_philo		*p;
	int			i;

	flag = false;
	i = 0;
	while (i < philo->share->info->number)
	{
		p = &philo[i];
		log_time = create_time(philo);
		//date race
		jugde_time = log_time - (p->active_time);
		if (jugde_time > p->share->info->time_die)
		{
			pthread_mutex_lock(&p->share->mutex_finish);
			put_log(philo, DIED);
			philo->share->finish = true;
			pthread_mutex_unlock(&p->share->mutex_finish);
			flag = true;
		}
		i++;
	}
	return (flag);
}

bool	is_stuffed(t_philo *philo)
{
	bool	flag;
	t_philo	*p;
	int		i;

	flag = true;
	i = 0;
	if (philo->share->info->must_eat == -1)
		return (false);
	while (i < philo->share->info->number)
	{
		p = &philo[i];
		pthread_mutex_lock(&p->mutex_philo);
		if (p->eat_count < p->share->info->must_eat)
			flag = false;
		pthread_mutex_unlock(&p->mutex_philo);
		i++;
	}
	return (flag);
}

bool	check_finish(t_philo *philo)
{
	bool	flag;

	pthread_mutex_lock(&philo->share->mutex_finish);
	flag = philo->share->finish;
	pthread_mutex_unlock(&philo->share->mutex_finish);
	return (flag);
}
