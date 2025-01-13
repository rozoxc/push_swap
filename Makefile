CC = cc
FLAGS = -Wall -Werror -Wextra 
NAME = push_swap
HEADER = push_swap.h

SRCS = mandatory/push.c \
		mandatory/rotate.c \
		mandatory/reverse_rotate.c \
		mandatory/swap.c \
		mandatory/push_swap.c \
		mandatory/parsing.c \
		mandatory/sort.c \
		mandatory/sort_helper.c \
		mandatory/radix.c \
		util/ft_atoi.c \
		util/ft_is_digit.c \
		util/ft_strcmp.c \
		util/ft_strlen.c \
		util/ft_count_numbers.c \
		util/split.c \

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