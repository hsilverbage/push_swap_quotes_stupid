.PHONY: clean fclean re bonus

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

LIST_HEADERS = lib_push_swap.h
SRCS =			ft_atoi.c			\
				ft_printf.c  		\
				ft_printf_utils.c

DIR_HEADERS 	= ./
DIR_OBJS 		= .objs/
RM				= rm -rf

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))

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
