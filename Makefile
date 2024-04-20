SRCS = push_swap_srcs/check_stack.c push_swap_srcs/filling_stack_a.c push_swap_srcs/ft_atio.c push_swap_srcs/ft_myoperations.c \
       push_swap_srcs/ft_myoperations2.c push_swap_srcs/ft_putstr.c push_swap_srcs/ft_split.c push_swap_srcs/ft_substr.c \
       push_swap_srcs/get_position_and_best_push.c push_swap_srcs/is_valid_argument.c push_swap_srcs/push_swap.c \
       push_swap_srcs/sort_stack_utils.c push_swap_srcs/sort_stack.c push_swap_srcs/utils.c push_swap_srcs/filling_stack_a_utils.c  

OBJS = $(SRCS:.c=.o)

BONUS = checker_srcs/checker.c checker_srcs/check_stack.c checker_srcs/filling_stack_a.c checker_srcs/ft_atoi.c checker_srcs/ft_myoperations.c \
        checker_srcs/ft_myoperations2.c checker_srcs/ft_putstr.c checker_srcs/ft_split.c checker_srcs/ft_substr.c \
		checker_srcs/is_valid_argument.c checker_srcs/ft_strcmp.c checker_srcs/utils.c 

BONUS_OBJS = $(BONUS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

clean_bonus:
	$(RM) $(BONUS_OBJS)

fclean: clean clean_bonus
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean $(NAME) $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)
