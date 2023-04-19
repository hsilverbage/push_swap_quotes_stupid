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

t_element	*ft_new_node(char **argv, int i)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->data = ft_atoi(argv[i]);
	new->next = NULL;
	return (new);
}

void	ft_fill_stack_a(int argc, char **argv, t_element *element_a)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		element_a->next = ft_new_node(argv, i);
		element_a = element_a->next;
		i++;
	}
	element_a = NULL;
}

void	ft_create_list(int argc, char **argv, t_stack *stack_a)
{
	t_element	*element_a;

	element_a = ft_new_node(argv, 1);
	stack_a->head = element_a;
	ft_fill_stack_a(argc, argv, element_a);
}
