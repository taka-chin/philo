#include "philo.h"

t_info	*init_info(int argc, char **input)
{
	t_info	*info;

	info = ft_calloc(1,sizeof(t_info));
	if (info == NULL)
	{
		ft_put_error(CALLOC_ERROR);
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
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	while (i < input->number)
	{
		fork_p = &fork[i];
		if (pthread_mutex_init(&fork_p->mutex_fork, NULL) != 0)
		{
			fork_destory(fork,i);
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
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	if (pthread_mutex_init(&share->mutex_finish, NULL) != 0)
	{
		/* share_destory(share); */
		return (NULL);
	}
	share->thread_num = 1;
	share->info = input;
	return (share);
}

t_philo	*init_philo(t_info *input, t_fork *fork, t_share *share)
{
	int		i;
	t_philo	*philo;
	pthread_mutex_t	*mutex_philo;

	i = 0;
	philo = ft_calloc(input->number, sizeof(t_philo));
	if (philo == NULL)
	{
		ft_put_error(CALLOC_ERROR);
		return (NULL);
	}
	mutex_philo = ft_calloc(1,sizeof(pthread_mutex_t));
	if(pthread_mutex_init(mutex_philo, NULL) != 0)
	{
		/* philo_destroy(philo); */
		return (NULL);
	}
	while (i < input->number)
	{
		philo[i].mutex_philo = mutex_philo ;
		philo[i].id = i + 1;
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[(i + 1) % input->number];
		philo[i].share = share;
		i++;
	}
	return (philo);
}
