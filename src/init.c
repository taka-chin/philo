#include "philo.h"

t_info	*init_info(int argc, char **input)
{
	t_info	*info;

	info = ft_calloc(sizeof(t_info), 1);
	if (info == NULL)
	{
		ft_put_error(MALLOC_ERROR);
		return (NULL);
	}
	info->number = ft_atoi(input[1]);
	info->time_die = ft_atoi(input[2]);
	info->time_eat = ft_atoi(input[3]);
	info->time_sleep = ft_atoi(input[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(input[5]);
	else
		info->must_eat = -1;
	return (info);
}

t_fork	*init_fork(t_info *input)
{
	t_fork	*fork;
	t_fork	*fork_p;
	int		i;

	i = 0;
	fork = ft_calloc(input->number, sizeof(t_fork));
	if (fork == NULL)
	{
		ft_put_error(MALLOC_ERROR);
		return (NULL);
	}
	while (i < input->number)
	{
		fork_p = &fork[i];
		if (pthread_mutex_init(&fork_p->fork, NULL) != 0)
		{
			ft_put_error(PTHREAD_ERROR);
			return (NULL);
		}
		i++;
	}
	return (fork);
}

t_share	*init_share(t_info *input)
{
	t_share	*share;

	share = ft_calloc(1, sizeof(t_share));
	if (share == NULL)
	{
		ft_put_error(MALLOC_ERROR);
		return (NULL);
	}
	if (pthread_mutex_init(&share->mutex_finish, NULL) != 0)
	{
		ft_put_error(PTHREAD_ERROR);
		return (NULL);
	}
	share->info = input;
	return (share);
}

t_philo	*init_philo(t_info *input, t_fork *fork, t_share *share)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = ft_calloc(input->number, sizeof(t_philo));
	if (philo == NULL)
	{
		ft_put_error(MALLOC_ERROR);
		return (NULL);
	}
	while (i < input->number)
	{
		if (pthread_mutex_init(&philo[i].mutex_philo, NULL) != 0)
		{
			ft_put_error(PTHREAD_ERROR);
			return (NULL);
		}
		philo[i].id = i + 1;
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[(i + 1) % input->number];
		philo[i].share = share;
		i++;
	}
	return (philo);
}
