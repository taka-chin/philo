#include "philo.h"

void ft_put_error(int e_error_type)
{
	if(e_error_type == ARGS_ERROR)
	{
		//printfもミスるかも
		printf("invaild args\n");
		exit(EX_USAGE);
	}
	else if(e_error_type == MALLOC_ERROR)
	{
		printf("PTHREAD_ERROR\n");
		exit(EXIT_FAILURE); 
	}
	else if(e_error_type == PTHREAD_ERROR)
	{
		printf("PTHREAD_ERROR\n");
		exit(EXIT_FAILURE); 
	}
}

