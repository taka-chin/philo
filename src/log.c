#include "philo.h"

/* #define FMT "%ld %d %s\n" */
/* #define EAT " is eating" */
/* #define DEAD " died " */

/* print_message(time, philo->id, EAT); */

/* void print_message(long int time, int philo, char *message) */
/* { */
/* 	printf(FMT, time, philo, message); */
/* } */



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
	else if(e_state == DIED)
		printf("[time:%ld] [philo:%d] died\n",tp.tv_sec,philo);
}
