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

#define ERROR 1

typedef struct s_info
{
	int number;
	int time_die;
	int time_eat; 
	int time_sleep;
	int must_eat;
}	t_info;

typedef struct s_share
{
	pthread_mutex_t	mutex_finish;
	bool			finish;
	struct timeval	start_time;
	t_info			*info;
}	t_share;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				last_id;
	bool			now_use;
}t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				eat_count;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	mutex_philo;
	/* struct timeval	active_time; */
	long int 	active_time;
	t_share			*share;
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

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
bool 	input_check(int argc, char **input);
long int create_time(t_philo *philo);
int		ft_put_error(int e_error_type);
void	put_log(t_philo *philo,int state);
void	debug_printf(t_info *s);
void	pthreads_create(t_philo *philo);
void	pthreads_join(t_philo *philo, pthread_t admin);
void	*eating(void *arg);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	debug_printf(t_info *s);
void	debug_printf_philo(t_philo *s);
void	*dead_or_alive(void *arg);
void	*observe(void *arg);
int		all_free(void *s1 ,void *s2,void *s3);
void	pthreads_destory(t_fork *fork, int number);
bool 	is_dead(t_philo *philo);
bool 	is_stuffed(t_philo *philo);
bool    check_finish(t_philo *philo);
t_info	*init_info(int argc, char **input);
t_fork	*init_fork(t_info* input);
t_share *init_share(t_info *input);
t_philo	*init_philo(t_info *input,t_fork *fork,t_share *share);

#endif
