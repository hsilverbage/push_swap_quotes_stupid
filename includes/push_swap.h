#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

#include "../library/lib_push_swap.h"

typedef	struct	s_element
{
	int					data;
	// int				index;
	struct s_element	*next;
}				t_element;

typedef	struct	s_stack
{
	t_element	*head;
	t_element	*tail;
	int			size;
}				t_stack;

int	ft_check_input(int argc, char **argv);

void	ft_create_list(int argc, char **argv, t_stack *stack_a);
void	ft_fill_stack_a(int argc, char **argv, t_element *element_a);
void	ft_free_stack_a(t_stack *stack);

t_element	*ft_new_node(char **argv, int i);

#endif
