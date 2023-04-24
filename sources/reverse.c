/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
 #include "../includes/push_swap.h"

int	ft_reverse_a(t_stack *stack_a)
{
	t_element	*last;
	t_element	*temp;

	last = stack_a->tail;
	temp = stack_a->head;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	last->next = stack_a->head;
	stack_a->head = last;
	ft_printf("rra\n");
	return (0);
}

int	ft_reverse_b(t_stack *stack_b)
{
	t_element	*last;
	t_element	*temp;

	if (!stack_b->head || stack_b->head->next != NULL)
		return (0);
	last = stack_b->tail;
	temp = stack_b->head;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	last->next = stack_b->head;
	stack_b->head = last;
	ft_printf("rrb\n");
	return (0);
}

int	ft_reverse_a_and_b(t_stack *stack_a, t_stack *stack_b)
{


	ft_printf("rrr\n");
	return (0);
}
