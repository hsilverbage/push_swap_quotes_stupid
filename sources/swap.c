/*
sa (swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/

#include "../includes/push_swap.h"

void	ft_swap_a(t_stack *stack_a)
{
	t_element	*first;
	t_element	*second;

	first = stack_a->head;
	printf("address of first : %p\n", &first);
	second = first->next;
	printf("address of 2nd : %p\n", &second);
	first = second;
	second = stack_a->head;

	stack_a->head = second;
	printf("address of first : %p\n", &first);
	printf("data of first : %d\n", first->data);
	printf("address of 2nd : %p\n", &second);
	printf("data of 2nd : %d\n", second->data);

	ft_printf("sa");
	ft_printf("\n");
}

void	ft_swap_b(t_stack stack_a)
{


	ft_printf("sb");
}

void	ft_swap_a_and_b(t_stack stack_a)
{


	ft_printf("ss");
}
