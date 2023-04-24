/*
ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.
rr : ra and rb at the same time.
*/

#include "../includes/push_swap.h"

void	ft_rotate_a(t_stack *stack_a)
{
	t_element	*temp;
	t_element	*first;

	first = stack_a->head;
	stack_a = stack_a->head->next;
	while (first->next != NULL)
	{
		first = first->next;

	}

}

void	ft_rotate_b(t_stack stack_a)
{



}

void	ft_rotate_a_and_b(stack_a)
{



}
