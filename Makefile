CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = push_swap
NAME_BONUS = checker
HEADER = mandatory/push_swap.h
BONUS_HEADER = bonus/checker.h
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
 util/ft_strlen.c \
 util/ft_count_numbers.c \
 util/split.c
BONUS_SRC = bonus/checker.c \
bonus/checker_utils.c \
bonus/get_next_line.c \
bonus/get_next_line_util.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -I./mandatory -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJ) $(OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(OBJS) -o $(NAME_BONUS)

bonus/%.o: bonus/%.c $(BONUS_HEADER)
	$(CC) $(FLAGS) -I./bonus -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
