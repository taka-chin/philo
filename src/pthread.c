#include "philo.h"

void *hogehoge(void *arg)
{
	pthread_mutex_t	*mut;

	mut = (pthread_mutex_t	*)arg;
	if(pthread_mutex_lock(mut) != 0)
		ft_put_error(PTHREAD_ERROR);
	printf("in hogehoge lock\n");
	if(pthread_mutex_unlock(mut) != 0)
		ft_put_error(PTHREAD_ERROR);
	return(NULL);
}

void pthreads_create(pthread_mutex_t *mut)
{
	pthread_t th1;
	pthread_t th2;

	if(pthread_create(&th1, NULL, hogehoge, mut) != 0)
		ft_put_error(PTHREAD_ERROR);

	if(pthread_create(&th2, NULL, hogehoge, mut) != 0)
		ft_put_error(PTHREAD_ERROR);

	if(pthread_join(th1,NULL) != 0)
		ft_put_error(PTHREAD_ERROR);

	if(pthread_join(th2,NULL) != 0)
		ft_put_error(PTHREAD_ERROR);

	if(pthread_mutex_destroy(mut) != 0)
		ft_put_error(PTHREAD_ERROR);
}
