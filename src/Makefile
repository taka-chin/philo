NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/repl.c	\
		$(SRCS_DIR)/init.c

RM = rm -rf

OBJS_DIR = objs
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

INCLUDES_DIR = includes
INCLUDES = -I$(INCLUDES_DIR) -I$(LIBRARY_DIR)/$(INCLUDES_DIR) -I$(RL_DIR)/include

$(NAME): $(OBJS) $(LIBRARY_AFILE)
	$(CC) $(CFLAGS) -o $@ $^ $(RL_FLAGS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBRARY_AFILE):
	$(MAKE) -C $(LIBRARY_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJS_DIR) $(LIBRARY_DIR)/$(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBRARY_AFILE)

re: fclean all

.PHONY: all clean fclean re
