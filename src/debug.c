#include "philo.h"

void debug_printf(t_info *s)
{
	printf("id :%d\n",s->number);
	printf("id :%d\n",s->time_die);
	printf("id :%d\n",s->time_eat);
	printf("id :%d\n",s->time_sleep);
	if(&(s->must_eat) != NULL)
		printf("id :%d\n",s->must_eat);
}

void debug_printf_philo(t_philo *s)
{
	printf("id :%d\n",s->id);
	printf("eat_count :%d\n",s->eat_count);
	printf("left fork :%d\n",s->left_fork->last_id);
	if(s->right_fork != NULL)
		printf("right fork :%d\n",s->right_fork->last_id);
}
