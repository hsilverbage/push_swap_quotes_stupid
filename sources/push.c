/*
pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/

#include "../includes/push_swap.h"

int	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*temp;

	if(stack_b->head == NULL)
		return(0);
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	temp->next = stack_a->head;
	stack_a->head = temp;

	ft_printf("pa\n");
	return (0);
}

int	ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*temp;

	if(stack_a->head == NULL)
		return(0);
	temp = stack_a->head;
	stack_a->head = stack_a->head->next;
	if(!stack_b->head)
	{
		stack_b->head = temp;
		stack_b->head->next = NULL;
		stack_b->size = 1;
		stack_b->tail = stack_b->head;
	}
	else
	{
		temp->next = stack_b->head;
		stack_b->head = temp;
		stack_b->size += 1;
	}
	stack_a->size -= 1;
	ft_printf("pb\n");
	return (0);
}
