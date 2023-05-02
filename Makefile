.PHONY: clean fclean re bonus

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

LIST_HEADERS = push_swap.h

SRCS =	sources/check_input.c	\
		sources/push.c			\
		sources/rotate.c		\
		sources/main.c			\
		sources/reverse.c		\
		sources/swap.c			\
		sources/list.c			\
		sources/radix.c			\
		sources/small_sort.c	\
		utils/ft_atol.c			\
		utils/ft_printf.c		\
		utils/ft_printf_utils.c


DIR_HEADERS 	= ./
DIR_OBJS 		= /../.objs/
RM				= rm -rf

OBJS = $(SRCS:.c=$(DIR_OBJS).o))

all : $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) $(LIST_HEADERS) Makefile
	$(AR) rcs $(NAME) $(OBJS)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(DIR_OBJS)%.o: %.c $(LIST_HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
