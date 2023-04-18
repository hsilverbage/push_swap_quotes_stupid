#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef	struct	s_element
{
	int					data;
	// int				index;
	struct s_element	*next;
}				t_element;


typedef	struct	s_stack
{
	t_element	*head;
}				t_stack;

void	ft_create_list(int argc, char **argv, t_stack *stack_a, t_element *element_a);

#endif
