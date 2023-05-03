.PHONY:		clean fclean re norm

NAME = push_swap

CC = cc -g3
CFLAGS = -Wall -Werror -Wextra -MMD -MP #-fsanitize=address
INCLUDES = -I ./includes
SRC_DIR = .
OBJ_DIR = .obj
DEPS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.d)


RED=\033[0;31m
BLUE=\033[0;34m
GREEN=\033[0;32m
YELLOW=\033[0;33m
END=\033[0m

SRC =	$(SRC_DIR)/main.c					\
		$(SRC_DIR)/utils/ft_atol.c			\
		$(SRC_DIR)/utils/ft_printf.c		\
		$(SRC_DIR)/utils/ft_printf_utils.c	\
		$(SRC_DIR)/utils/ft_bzero.c			\
		$(SRC_DIR)/sources/list.c			\
		$(SRC_DIR)/sources/push.c			\
		$(SRC_DIR)/sources/reverse.c		\
		$(SRC_DIR)/sources/small_sort.c		\
		$(SRC_DIR)/sources/check_input.c	\
		$(SRC_DIR)/sources/radix.c			\
		$(SRC_DIR)/sources/rotate.c			\
		$(SRC_DIR)/sources/swap.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)Compilation succeded ! ✔️$(END)"

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/sources $(OBJ_DIR)/utils
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

norm:
	@norminette | grep "Error" && echo "$(RED)Norminette KO!$(END)" || echo "$(GREEN)Norminette OK!$(END)"

clean:
	@echo "$(YELLOW)Deleting all files 🗑$(END)"
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)Deleting the final program 🗑 $(END)"
		@rm -f $(NAME)

re: fclean norm all
