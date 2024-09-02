NAME = philo

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf
HEADER = philo.h
PARSING = parsing/check_args.c parsing/initialize.c parsing/mutex_init.c parsing/philos_init.c parsing/utils.c parsing/about_time.c
PHILO_SIMULATION = simulation/join_routine.c simulation/monitor_simu.c \
					simulation/philos_moves.c simulation/simulation.c simulation/thread_routine.c
FILES = $(PARSING) $(PHILO_SIMULATION) main.c
OBJS = $(FILES:.c=.o) 

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
