#include "../include/philo.h"

int main(int argc,char *argv[])
{
	t_info *input;
	t_fork *fork;
	t_share *share;
	t_philo *philo;

	if(!input_check(argc, argv))
		return(1);
	input = init_info(argc, argv);
	if(!input)
		return(1);
	fork = init_fork(input);
	if(!fork)
		return(all_free(input, NULL,NULL));
	share = init_share(input);
	if(!share)
	{
	/* 	// fork_destory(fork,-1); */
		return(all_free(input, fork,NULL));
	}
	philo = init_philo(input,fork,share);
	if(!philo)
	{
	/* 	// fork_destory(fork,-1); */
	/* 	// share_destory(share); */
		return(all_free(input, fork,share));
	}
	pthreads_create(philo);
	pthreads_join(philo);
	/* pthreads_destory(fork,share,philo,input->number); */
	return (0);
}
