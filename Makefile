.PHONY:         clean fclean re norm

NAME = push_swap

CC = gcc -g3

SRC_DIR = .
OBJ_DIR = .obj


RED=\033[0;31m
BLUE=\033[0;34m
GREEN=\033[0;32m
YELLOW=\033[0;33m
END=\033[0m

SRC =	$(SRC_DIR)/main.c					\
		$(SRC_DIR)/utils/ft_atol.c			\
		$(SRC_DIR)/utils/ft_printf.c		\
		$(SRC_DIR)/utils/ft_printf_utils.c	\
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
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)Compilation succeded ! ✔️$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/sources $(OBJ_DIR)/utils
	@$(CC) $(CFLAGS) -c $< -o $@

norm:
	@if ! norminette | grep -v "OK" > /dev/null; then \
		echo -e "$(GREEN)Norminette succeded ! ✔️$(END)"; \
	else \
		norminette | grep -v "OK" | grep --color=always "$(RED)KO$(END)"; \
	fi

clean:
	@echo -e "$(YELLOW)Deleting all files 🗑$(END)"
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo -e "$(BLUE)Deleting the final program 🗑$(END)"
		@rm -f $(NAME)

re: fclean all norm
