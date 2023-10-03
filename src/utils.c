#include "philo.h"

int	all_free(void *s1, void *s2, void *s3)
{
	printf("all free\n");
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (s3 != NULL)
		free(s2);
	return (1);
}

int	all_destory(void *s1, void *s2, void *s3)
{
	printf("all destroy\n");
	if (s1 != NULL)
		pthread_mutex_destroy(s1);
	if (s2 != NULL)
		pthread_mutex_destroy(s1);
	if (s3 != NULL)
		pthread_mutex_destroy(s1);
	return (1);
}
