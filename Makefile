CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = push_swap           # Changed from push.a to push_swap
HEADER = push_swap.h

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c print_address.c \
		ft_strlen.c Convert_hex.c hex.c  unsigned.c ft_is_digit.c \
		push_swap.c ft_atoi.c ft_strcmp.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re