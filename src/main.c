#include "philo.h"

void debug_printf(t_args *s)
{
	printf("number :%d\n",s->number);
	printf("number :%d\n",s->time_die);
	printf("number :%d\n",s->time_eat);
	printf("number :%d\n",s->time_sleep);
	if(&(s->must_eat) != NULL)
		printf("number :%d\n",s->must_eat);
}

void debug_printf_philo(t_philo *s)
{
	printf("id :%d\n",s->id);
	printf("state :%d\n",s->state);
	printf("eat_count :%d\n",s->eat_count);
	printf("last_count :%d\n",s->last_eat_time);
	printf("left fork :%d\n",s->left_fork->last_id);
	printf("right fork :%d\n",s->right_fork->last_id);
}

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

t_fork init_fork(t_args* input)
{
	t_fork *fork;
	pthread_mutex_t mut ;
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
		fork[i].fork = pthread_mutex_init(&mut,NULL);
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
	philo = malloc(sizeof(t_philo )*((input->number)+1));
	if(philo == NULL)
		free_philo(philo);
	while(i < input->number)
	{
		philo[i].id = input->number;
		philo[i].state = BEFORE_EAT;
		philo[i].eat_count = 0;
		philo[i].last_eat_time = 0;
		philo[i].left_fork = fork[i];
		i++;
	}
	philo[i] = NULL:
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
	pthreads_create(&mut);
	fork = init_fork(input);
	philo = init_philo(input,fork);
	/* init_fork(input->number); */

	put_log(input->number,BEFORE_EAT);
	put_log(input->number,EAT);
	put_log(input->number,SLEEP);
	put_log(input->number,THINK);
	put_log(input->number,DIED);
}
