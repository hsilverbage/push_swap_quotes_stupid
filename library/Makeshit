# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 18:02:30 by henrik            #+#    #+#              #
#    Updated: 2022/12/27 10:14:24 by hsilverb         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re bonus

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

LIST_HEADERS = ft_printf.h

SRCS =			ft_printf.c	\
				ft_printf_nbr.c


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
