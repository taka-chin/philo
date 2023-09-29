#include "philo.h"

void all_free(void *s1,void *s2)
{
	printf("all free\n");
	if(s1 != NULL)
		free(s1);
	if(s2 != NULL)
		free(s2);
}

void pthreads_join(t_philo *philo)
{
	t_philo *p;
	int i;

	i = 0;
	while(i < philo->share->info->number)
	{
		p = &philo[i];
		if(pthread_join(p->thread, NULL) != 0)
		{
			/* all_free(); */
			ft_put_error(PTHREAD_ERROR);
		}
		i++;
	}
}

void pthreads_create(t_philo *philo)
{
	t_philo *philo_p;
	pthread_t admin;
	int	i;
	struct timeval tp;

	i = 0;
	gettimeofday(&tp,NULL);
	if(pthread_create(&admin, NULL,observe, (void*)philo) != 0)
	{
		/* all_free(); */
		ft_put_error(PTHREAD_ERROR);
	}
	while(i < philo->share->info->number)
	{
		philo_p = &philo[i];
		philo_p->share->start_time.tv_sec = tp.tv_sec;
		philo_p->share->start_time.tv_usec = tp.tv_usec;
		/* philo_p->last_time.tv_sec = tp.tv_sec; */
		/* philo_p->last_time.tv_usec = tp.tv_usec; */
		if(pthread_create(&philo_p->thread, NULL, dead_or_alive, (void*)philo_p) != 0)
		{
			/* all_free(); */
			ft_put_error(PTHREAD_ERROR);
		}
		i++;
	}
}

void pthreads_destory(t_fork *fork, int number)
{
	t_fork *fork_p;
	int	i;

	i = 0;
	while(i < number)
	{
		fork_p = &fork[i];
		if(pthread_mutex_destroy(&fork_p->fork) != 0)
		{
			/* all_free(); */
			ft_put_error(PTHREAD_ERROR);
		}
		i++;
	}
}

