
.PHONY: clean fclean re bonus

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIST_HEADERS = includes/push_swap.h

LIBS = library/libft.a

SRCS = 	sources/check_input.c	\
		sources/push.c			\
		sources/rotate.c		\
		sources/main.c			\
		sources/reverse.c		\
		sources/swap.c			\
		sources/list.c			\
		sources/radix.c			\
		sources/small_sort.c

DIR_HEADERS 	= ./includes
DIR_OBJS 		= .objs/
RM				= rm -rf

OBJS = $(SRC:./%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(LIBS):
	$(MAKE) -C library all

$(NAME): $(LIBS) $(DIR_OBJS) $(OBJS) $(LIST_HEADERS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)


$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(DIR_OBJS)%.o: %.c $(LIST_HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)

clean:
	make clean -C library
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C library
	$(RM) $(NAME)

re:	fclean all


