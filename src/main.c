#include "philo.h"

int main(int argc,char *argv[])
{
	t_info *input;
	t_fork *fork;
	t_share *share;
	t_philo *philo;

	if(argc < 5 || argc >= 7)
	{
		ft_put_error(ARGS_ERROR);
		return(1);
	}
	if(input_check(argv) != 0)
		return(1);
	input = init_info(argc, argv);
	if(input == NULL)
		return(1);
	fork = init_fork(input);
	if(fork == NULL)
		return(1);
	share = init_share(input);
	if(share == NULL)
		return(1);
	philo = init_philo(input,fork,share);
	if(philo == NULL)
		return(1);
	//error handring
	//sart_time;
	pthreads_create(philo);
	pthreads_join(philo);
	pthreads_destory(fork, input->number);

	return (0);
}
