#include "philo.h"

int input_check(char **input)
{
	const char	*str;

	while (*++input)
	{
		str = *input;
		if (str[0] == '+' || str[0] == '-')
			str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
			{
				ft_put_error(ARGS_ERROR);
				return(1);
			}
			str++;
		}
	}
	return(0);
}
