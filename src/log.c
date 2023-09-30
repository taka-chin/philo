#include "philo.h"

long int create_time(t_philo *philo)
{
	struct timeval tp;
	long int log_time;

	gettimeofday(&tp,NULL);
	log_time = (tp.tv_sec - philo->share->start_time.tv_sec) * 1000000;
	log_time += tp.tv_usec - philo->share->start_time.tv_usec;
	log_time /= 1000;
	return(log_time);
}

void put_log(t_philo *philo,int e_state)
{
	long int log_time;

	pthread_mutex_lock(&philo->share->mutex_finish);
	/* gettimeofday(&tp,NULL); */
	/* log_time = (tp.tv_sec - philo->share->start_time.tv_sec) * 1000000; */
	/* log_time += tp.tv_usec - philo->share->start_time.tv_usec; */
	/* log_time /= 1000; */
	log_time = create_time(philo);
	if(philo->share->finish)
		;
	else if(e_state == BEFORE_EAT)
		printf("%ld %d has taken a fork\n",log_time,philo->id);
	else if(e_state == EAT)
		printf("%ld %d is eating\n",log_time,philo->id);
	else if(e_state == SLEEP)
		printf("%ld %d is sleeping\n",log_time,philo->id);
	else if(e_state == THINK)
		printf("%ld %d is thinking\n",log_time,philo->id);
	pthread_mutex_unlock(&philo->share->mutex_finish);
}
