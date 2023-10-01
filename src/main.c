#include "philo.h"

int main(int argc,char *argv[])
{
	t_info *input;
	t_fork *fork;
	t_share *share;
	t_philo *philo;

	if(input_check(argc, argv) == false)
		return(ft_put_error(ARGS_ERROR));
	input = init_info(argc, argv);
	if(!input)
		return(ft_put_error(ARGS_ERROR));
	fork = init_fork(input);
	if(!fork)
		return(ft_put_error(ARGS_ERROR));
	share = init_share(input);
	if(!share)
		return(ft_put_error(ARGS_ERROR));
	philo = init_philo(input,fork,share);
	if(!philo)
		return(ft_put_error(ARGS_ERROR));
	pthreads_create(philo);
	pthreads_destory(fork, input->number);
	return (0);
}
