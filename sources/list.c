/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:39 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/02 19:38:01 by henrik           ###   ########lyon.fr   */
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
	}
}

t_element	*ft_new_node(char **argv, int i)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->data = ft_atol(argv[i]);
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_fill_stack_a(int argc, char **argv, t_stack *stack_a)
{
	t_element	*new;
	int			i;

	new = stack_a->head;
	i = 2;
	while (i < argc)
	{
		new->next = ft_new_node(argv, i);
		new = new->next;
		if (new->data > stack_a->max)
			stack_a->max = new->data;
		if (new->data < stack_a->min)
			stack_a->min = new->data;
		i++;
		new->next = NULL;
	}
}

void	ft_set_index(t_stack *stack_a)
{
	t_element	*temp;
	t_element	*checker;
	int			index;

	temp = stack_a->head;
	index = 1;
	while (index <= stack_a->size)
	{
		while (temp->index != -1)
			temp = temp->next;
		checker = temp->next;
		while (checker != NULL)
		{
			if (checker->data < temp->data && checker->index == -1)
				temp = checker;
			checker = checker->next;
		}
		temp->index = index++;
		temp = stack_a->head;
	}
}

void	ft_create_list(int argc, char **argv, t_stack *stack_a)
{
	t_element	*new;

	new = ft_new_node(argv, 1);
	stack_a->head = new;
	stack_a->max = new->data;
	stack_a->min = new->data;
	stack_a->size = argc - 1;
	ft_fill_stack_a(argc, argv, stack_a);
	ft_set_index(stack_a);
}
