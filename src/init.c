#include "philo.h"

t_args *init_args(int argc, char **input)
{
	t_args *info;

	info = ft_calloc(sizeof(t_args), 1);
	info->number = ft_atoi(input[1]);
	info->time_die = ft_atoi(input[2]);
	info->time_eat = ft_atoi(input[3]);
	info->time_sleep = ft_atoi(input[4]);
	if(argc == 6)
		info->must_eat = ft_atoi(input[5]);
	else
		info->must_eat = -1;
	return(info);
}

t_fork *init_fork(t_args* input)
{
	t_fork *fork;
	t_fork *f;
	int i;

	i = 0;
	fork = ft_calloc(input->number, sizeof(t_fork));
	if(fork == NULL)
	{
		free(fork);
		ft_put_error(MALLOC_ERROR);
	}
	while(i < input->number)
	{
		f = &fork[i];
		if(pthread_mutex_init(&f->fork,NULL) != 0)
			ft_put_error(PTHREAD_ERROR);
		i++;
	}
	return(fork);
}

t_philo *init_philo(t_args *input,t_fork *fork)
{
	int i;
	t_philo *philo;

	i = 0;
	philo = ft_calloc(input->number, sizeof(t_philo));
	if(philo == NULL)
	{
		ft_put_error(MALLOC_ERROR);
		return (NULL);
	}
	while(i < input->number)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[(i + 1) % input->number];
		philo[i].info = input;
		i++;
	}
	return(philo);
}
