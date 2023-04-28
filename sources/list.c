/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:39 by hsilverb          #+#    #+#             */
/*   Updated: 2023/04/28 19:07:45 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_stack *stack)
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

void	ft_fill_stack_a(int argc, char **argv, t_stack *stack_a)
{
	t_element	*new;
	int	i;

	i = 2;
	while (i < argc)
	{
		new->next = ft_new_node(argv, i);
		new = new->next;
		if (new->data > stack_a->max)
			stack_a->max = new->data;
		if (new->data < stack_a->min)
			stack_a->min = new->data;
		if (new->next == NULL)
			stack_a->last = new;
		i++;
	}
	new = NULL;
}

void	ft_create_list(int argc, char **argv, t_stack *stack_a)
{
	t_element	*new;

	new = ft_new_node(argv, 1);
	stack_a->head = new;
	stack_a->max = new->data;
	stack_a->min = new->data;
	ft_fill_stack_a(argc, argv, stack_a);
	stack_a->size = argc - 1;

}
