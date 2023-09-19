#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sysexits.h>
#include <pthread.h>
#include <limits.h>

typedef struct s_args
{
	/* The number of philosophers and also the number */
	/* of forks. */
	int number;

	/* If a philosopher didn’t start eating time_to_die */
	/* milliseconds since the beginning of their last meal or the beginning of the simulation, they die. */
	int time_die;

	/* The time it takes for a philosopher to eat. */
	/* During that time, they will need to hold two forks. */
	int time_eat; 

	/* The time a philosopher will spend sleeping. */
	int time_sleep;

	/* If all */
	/* philosophers have eaten at least number_of_times_each_philosopher_must_eat */
	/* times, the simulation stops. If not specified, the simulation stops when a */
	/* philosopher dies. */
	int must_eat;
}t_args;

enum e_state
{
	BEFORE_EAT,
	EAT,
	SLEEP,
	THINK,
	DIED
};

enum e_error_type
{
	ARGS_ERROR,
	PTHREAD_ERROR
};

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void ft_put_error(int e_error_type);
void put_log(int philo,int state);
void debug_printf(t_args *s);
t_args *init_args(char **input);
void pthreads_create();
void *hogehoge(void *mut);

#endif
