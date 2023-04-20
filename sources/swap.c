/*
sa (swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/

#include "../includes/push_swap.h"

void	ft_swap_a(t_stack stack_a)
{
	t_element	*first;
	t_element	*second;
	t_element	*temp;

	first = stack_a->head;
	second = first->next;

	stack_a->head = second;
	

	ft_printf("sa");
}

void	ft_swap_b(t_stack stack_a)
{


	ft_printf("sb");
}

void	ft_swap_a_and_b(t_stack stack_a)
{


	ft_printf("ss");
}
