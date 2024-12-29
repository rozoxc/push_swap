CC = cc
FLAGS = -Wall -Werror -Wextra 
NAME = push_swap
HEADER = push_swap.h

SRCS = mandatory/operations.c \
		mandatory/push_swap.c \
		mandatory/parsing.c \
		mandatory/sort.c \
		util/ft_atoi.c \
		util/ft_is_digit.c \
		util/ft_strcmp.c \
		util/ft_strlen.c \
		util/check_args.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS)  $(OBJS) -o $(NAME)

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -I./mandatory -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re