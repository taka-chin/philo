#include "philo.h"

void all_free(void *s1,void *s2)
{
	printf("all free\n");
	if(s1 != NULL)
		free(s1);
	if(s2 != NULL)
		free(s2);
}
