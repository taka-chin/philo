#include "philo.h"

void fork_destory(t_fork *fork,int i)
{
	while(--i)	
	{
		pthread_mutex_destroy(&(fork[i].mutex_fork));
	}
}
