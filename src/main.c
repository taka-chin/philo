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

/* init_fork(int number) */
/* { */

/* } */

int main(int argc,char *argv[])
{
	t_args *input;
	pthread_mutex_t mut ;

	if(argc < 5 || argc >= 7)
		ft_put_error(ARGS_ERROR);
	pthread_mutex_init(&mut,NULL);
	input = init_args(argv);
	pthreads_create(&mut);
	/* init_fork(input->number); */

	put_log(input->number,BEFORE_EAT);
	put_log(input->number,EAT);
	put_log(input->number,SLEEP);
	put_log(input->number,THINK);
	put_log(input->number,DIED);
}
