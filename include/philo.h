#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sysexits.h>
#include <pthread.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>


typedef struct s_args
{
	/* The number of philosophers and forks */
	int number;

	/* time_to_die */
	int time_die;

	/* The time it takes for a philosopher to eat. */
	int time_eat; 

	/* The time a philosopher will spend sleeping. */
	int time_sleep;

	/* philosophers have eaten at least */ 
	int must_eat;
}t_args;

typedef struct s_fork
{
	pthread_mutex_t fork;
	int last_id;
	bool now_use;
}t_fork;

typedef struct s_philo
{
	int id;
	int state;
	int eat_count;
	pthread_t thread;
	t_fork *left_fork;
	t_fork *right_fork;
	t_args *info;
	struct timeval start_time;
	struct timeval last_time;
}t_philo;

enum e_state
{
	EAT,
	BEFORE_EAT,
	SLEEP,
	THINK,
	DIED
};

enum e_error_type
{
	ARGS_ERROR,
	MALLOC_ERROR,
	PTHREAD_ERROR
};

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void ft_put_error(int e_error_type);
void put_log(t_philo *philo,int state);
void debug_printf(t_args *s);
t_args *init_args(int argc, char **input);
void pthreads_create(t_philo *philo);
void pthreads_join(t_philo *philo);
void *eating(void *arg);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void debug_printf(t_args *s);
void debug_printf_philo(t_philo *s);
void *dead_or_alive(void *arg);
void all_free();
void pthreads_destory(t_fork *fork, int number);
t_args *init_args(int argc, char **input);
t_fork *init_fork(t_args* input);
t_philo *init_philo(t_args *input,t_fork *fork);

#endif
