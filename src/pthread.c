#include "philo.h"

void all_free()
{
	printf("all free\n");
}

//state
/* void *eating(void *arg) */
/* { */
/* 	t_philo *philo; */

/* 	philo = (t_philo *)arg; */
/* 	if(pthread_mutex_lock(philo->left_fork) != 0) */
/* 	{ */
/* 		all_free(); */
/* 		ft_put_error(PTHREAD_ERROR); */
/* 	} */
/* 	if(pthread_mutex_lock(philo->right_fork) != 0) */
/* 	{ */
/* 		all_free(); */
/* 		ft_put_error(PTHREAD_ERROR); */
/* 	} */
/* 	put_log(philo->id,EAT); */
/* 	if(pthread_mutex_unlock(philo->left_fork) != 0) */
/* 	{ */
/* 		all_free(); */
/* 		ft_put_error(PTHREAD_ERROR); */
/* 	} */
/* 	if(pthread_mutex_unlock(philo->right_fork) != 0) */
/* 	{ */
/* 		all_free(); */
/* 		ft_put_error(PTHREAD_ERROR); */
/* 	} */
/* 	return(NULL); */
/* } */

void pthreads_join(t_philo *philo)
{
	t_philo *p;
	int i;

	i = 0;
	while(i < philo->info->number)
	{
		p = &philo[i];
		if(pthread_join(p->thread, NULL) != 0)
		{
			all_free();
			ft_put_error(PTHREAD_ERROR);
		}
		i++;
	}
}

/* void pthreads_create(pthread_mutex_t *mut) */
void pthreads_create(t_philo *philo)
{
	t_philo *p;
	int	i;

	i = 0;
	while(i < philo->info->number)
	{
		p = &philo[i];
		if(pthread_create(&p->thread, NULL, dead_or_alive, p) != 0)
		{
			all_free();
			ft_put_error(PTHREAD_ERROR);
		}
		i++;
	}
}
	/* if(pthread_mutex_destroy(mut) != 0) */
	/* 	ft_put_error(PTHREAD_ERROR); */

void pthreads_destory(t_fork *fork, int number)
{
	t_fork *f;
	int	i;

	i = 0;
	while(i < number)
	{
		f = &fork[i];
		if(pthread_mutex_destroy(&f->fork) != 0)
		{
			all_free();
			ft_put_error(PTHREAD_ERROR);
		}
		i++;
	}
}

