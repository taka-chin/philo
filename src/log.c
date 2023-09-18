#include "philo.h"

void put_log(int philo,int e_state)
{
	struct timeval tp;

	gettimeofday(&tp,NULL);

	if(e_state == BEFORE_EAT)
		printf("[time:%ld] [philo:%d] has taken a fork\n",tp.tv_sec,philo);
	else if(e_state == EAT)
		printf("[time:%ld] [philo:%d] is eating\n",tp.tv_sec,philo);
	else if(e_state == SLEEP)
		printf("[time:%ld] [philo:%d] is sleeping\n",tp.tv_sec,philo);
	else if(e_state == THINK)
		printf("[time:%ld] [philo:%d] is thinking\n",tp.tv_sec,philo);
	else if(e_state == THINK)
		printf("[time:%ld] [philo:%d] died\n",tp.tv_sec,philo);
}
