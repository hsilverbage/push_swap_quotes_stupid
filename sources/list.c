// #include "../includes/push_swap.h"

// int	ft_create_list(int argc, char **argv, t_stack *stack_a, t_element *element_a)
// {
// 	int	i;

// 	i = 2;

// 	element_a = malloc(sizeof(t_element));
// 	if (!element_a)
// 		return (0);
// 	element_a->data = ft_atoi(argv[1]);
// 	stack_a->head = element_a;
// 	while (i <= argc)
// 	{
// 		element_a->next = malloc(sizeof(t_element));
// 		if (!element_a)
// 			return (0);
// 		element_a = element_a->next;
// 		element_a->data = ft_atoi(argv[i]);
// 		i++;
// 		element_a->next = NULL;
// 	}
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

t_element	*ft_new_node(char **argv)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->data = atoi(argv[1]);
	new->next = NULL;
	return (new);
}

void	ft_create_list(int argc, char **argv, t_stack *stack_a, t_element *element_a)
{
	element_a = ft_new_node(argv);
	stack_a->head = element_a;
	//ft_fill_stack_a();

}