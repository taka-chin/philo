#include "../include/philo.h"

void ft_put_error(int e_error_type)
{
	if(e_error_type == ARGS_ERROR)
		write(2,"invaild args\n",14);
	else if(e_error_type == CALLOC_ERROR)
		write(2,"calloc error\n",14);
	else if(e_error_type == PTHREAD_ERROR)
		write(2,"pthreads error\n",15);
}
