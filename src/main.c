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
	philo->number = atoi(input[0]);
	philo->time_die = atoi(input[1]);
	philo->time_eat = atoi(input[2]);
	philo->time_sleep = atoi(input[3]);
	if(input[4] != NULL)
		philo->must_eat = atoi(input[4]);
	return(philo);
}

/* void *hogehoge(pthread_mutex_t *mut) */
/* { */
/* 	if(pthread_mutex_lock(mut) != 0) */
/* 		ft_put_error(PTHREAD_ERROR); */
/* 	printf("in hogehoge lock"); */
/* 	if(pthread_mutex_unlock(mut) != 0) */
/* 		ft_put_error(PTHREAD_ERROR); */
/* 	return(NULL); */
/* } */

int main(int argc,char *argv[])
{
	t_args *input;
	pthread_mutex_t mut ;

	pthread_mutex_init(&mut,NULL);
	if(argc < 5 || argc >= 7)
		ft_put_error(ARGS_ERROR);
	input = init_args(argv);
	pthreads_create(&mut);

	put_log(input->number,BEFORE_EAT);
	put_log(input->number,EAT);
	put_log(input->number,SLEEP);
	put_log(input->number,THINK);
	put_log(input->number,DIED);
}
