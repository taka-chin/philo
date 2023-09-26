#include "philo.h"

int main(int argc,char *argv[])
{
	t_args *input;
	t_fork *fork;
	t_philo *philo;

	if(argc < 5 || argc >= 7)
		ft_put_error(ARGS_ERROR);
	input = init_args(argc, argv);
	fork = init_fork(input);
	philo = init_philo(input,fork);
	pthreads_create(philo);
	pthreads_join(philo);
	pthreads_destory(fork, input->number);

	return (0);
}
