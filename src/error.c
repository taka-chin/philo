#include "philo.h"

void ft_put_error(int e_error_type)
{
	if(e_error_type == ARGS_ERROR)
	{
		printf("invaild args\n");
		exit(1);
	}
	else if(e_error_type == MALLOC_ERROR)
		printf("PTHREAD_ERROR\n");
	else if(e_error_type == PTHREAD_ERROR)
		printf("PTHREAD_ERROR\n");
}

