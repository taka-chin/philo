NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

SRCS	=	main.c \
			error.c \
			log.c \
			pthread.c \

OBJS    =    ${SRCS:.c=.o}

RM    =    rm -f

all:${NAME}

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	${RM} ${OBJS} 
fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY:
	all clean fclean re 
