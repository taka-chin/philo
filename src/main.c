#include "philo.h"

static void	input_check(char **input)
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
				ft_put_error(ARGS_ERROR);
			str++;
		}
	}
}

int main(int argc,char *argv[])
{
	t_args *input;
	t_fork *fork;
	t_philo *philo;

	if(argc < 5 || argc >= 7)
		ft_put_error(ARGS_ERROR);
	input_check(argv);
	input = init_args(argc, argv);
	fork = init_fork(input);
	philo = init_philo(input,fork);
	pthreads_create(philo);
	pthreads_join(philo);
	pthreads_destory(fork, input->number);

	return (0);
}
