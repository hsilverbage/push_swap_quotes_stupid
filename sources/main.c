// #include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

void	ft_free_stack_a(t_stack *stack)
{
	t_element	*prev;

	if (stack->head != NULL)
	{
		while (stack->head != NULL)
		{
			prev = stack->head;
			stack->head = stack->head->next;
			free(prev);
		}
		free(stack->head);
	}
	free(stack);
}

int main(int argc, char **argv)
{
	t_stack		*stack_a;
//	t_stack		*stack_b;
	t_element	*element_a;

	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	element_a = malloc(sizeof(t_element));
	if (!element_a)
		return (0);
//	stack_b = NULL;

	ft_create_list(argc, argv, stack_a, element_a);
	printf("%d", stack_a->head->data);
	ft_free_stack_a(stack_a);
	if (element_a)
		free(element_a);
	
	printf("\n");

	return (0);
}
