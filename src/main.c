#include "philo.h"

t_args *init_args(char **input)
{
	t_args *philo;

	philo = malloc(sizeof(t_args *));
	philo->number = ft_atoi(input[1]);
	philo->time_die = ft_atoi(input[2]);
	philo->time_eat = ft_atoi(input[3]);
	philo->time_sleep = ft_atoi(input[4]);
	if(input[5] != NULL)
		philo->must_eat = ft_atoi(input[5]);
	return(philo);
}

t_fork *init_fork(t_args* input)
{
	t_fork *fork;
	int i;

	i = 0;
	fork = ft_calloc(input->number,sizeof(t_fork));
	if(fork == NULL)
	{
		free(fork);
		ft_put_error(MALLOC_ERROR);
	}
	while(i < input->number)
	{
		if(pthread_mutex_init(&fork[i].fork,NULL) != 0)
			ft_put_error(PTHREAD_ERROR);
		fork[i].last_id = 0;
		fork[i].now_use = false;
		i++;
	}
	return(fork);
}

t_philo *init_philo(t_args *input,t_fork *fork)
{
	int i;
	t_philo *philo;

	i = 0;
	philo = ft_calloc(input->number + 1,sizeof(t_philo));
	if(philo == NULL)
		free(philo);
	while(i < input->number)
	{
		philo[i].id = input->number;
		philo[i].state = BEFORE_EAT;
		philo[i].eat_count = 0;
		philo[i].last_eat_time = 0;
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = NULL;
		i++;
	}
	return(philo);
}

int main(int argc,char *argv[])
{
	t_args *input;
	t_fork *fork;
	t_philo *philo;

	if(argc < 5 || argc >= 7)
		ft_put_error(ARGS_ERROR);
	input = init_args(argv);
	fork = init_fork(input);
	philo = init_philo(input,fork);
	pthreads_create(philo[0].left_fork);
	debug_printf_philo(philo);
	/* init_fork(input->number); */

	put_log(input->number,BEFORE_EAT);
	put_log(input->number,EAT);
	put_log(input->number,SLEEP);
	put_log(input->number,THINK);
	put_log(input->number,DIED);
}
